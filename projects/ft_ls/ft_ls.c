#include "header.h"
#include "ft.h"

void printSimpleLs (t_list *list)
{
	if (list == NULL){
		printf("\n");
		return;
	}
	while (list){
		if (strncmp(list->element->d_name, ".", 1) != 0)
			printf("%s\n", list->element->d_name);
		list = list->next_element;
	}
}

char * ft_realloc(char* str, int strSize, int newSize)
{
	char *ptr;
	if (newSize == 0)
		return NULL;
	ptr = malloc(sizeof(*ptr) * newSize + 1);
	if (ptr == NULL){
		return NULL;
	}
	int i = 0;
	for (; i < strSize; i++){
		ptr[i] = str[i];
	}
	while (i < newSize){
		ptr[i] = '\0';
		i++;
	}
	
	free(str);
	return ptr;
}

char *line_creation( int current_len, int next_len, char *next_folder, char *current_folder)
{
	current_folder = ft_realloc(current_folder, current_len, current_len + next_len);
	strncpy(current_folder + current_len, next_folder, next_len);
	return current_folder;
}

void  RecursiveLs(t_stack *stack)
{
	char *current_folder;
	
	current_folder = malloc(sizeof(*current_folder) * strlen (stack->first_element->path_name) + 1);
	current_folder[0] = '\0';
	t_list *current_list;
	current_list = malloc(sizeof(*current_list));	
	while (stack->first_element){
		current_folder = strcpy (current_folder, stack->first_element->path_name);
		
		printf("%s:\n", current_folder);
		current_list = createList (current_folder);
		printSimpleLs (current_list);
		popStack (stack);
		while (current_list){
			char *file_name = current_list->element->d_name;
			if (current_list->element->d_type == DT_DIR
				&& strcmp(file_name, ".") != 0
				&& strcmp (file_name, "..") != 0){
				printf("\n");
				char *new_path = NULL;
				new_path = current_folder;
				//printf("current_folder : %s\n", current_folder);
				//printf("new_path : %s\n", new_path);
				new_path = line_creation (strlen (new_path), 1, "/", new_path);
				new_path = line_creation(strlen(new_path), strlen(file_name),
								file_name, new_path);
				
				stack = pushStack(stack, new_path);
				//printf("new_path modified : %s\n", new_path);
				
			}
			current_list = current_list->next_element;
		}
	}
	return;
}

void ftLsOption (t_list *entry_list, char **av, int ac, t_stack *stack)
{
	bool recu = false;
	
	int i;
	for (i = 1; i < ac; i++){
		if (strcmp(av[i], "-r") == 0)
			entry_list = reverseList(entry_list);
		if (strcmp(av[i], "-R") == 0){
			recu = true;
		}
	}
	if ((recu == false))
		printSimpleLs(entry_list);
	
	else
		RecursiveLs (stack);
	
}

void ftLs (char **av, int ac)
{
	t_stack *stack;
	stack = createStack(av[ac - 1]);
	if (stack == NULL) {
		printf("error creation stack\n");
		return;
	}
	t_list *entry_list;
	entry_list = createList(av[ac - 1]);
	if ((entry_list == NULL))
		return;	
	if ((ac > 2))
		ftLsOption(entry_list, av, ac, stack);
	else 
		printSimpleLs(entry_list);

}

int main (int argc, char **argv)
{	
	if (argc < 2)
		return 1;
	ftLs(argv, argc);
	return 0;
}