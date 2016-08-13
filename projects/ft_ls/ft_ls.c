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

void addSeparator (char *string)
{
	int size;
	size = strlen (string);
	if ((string[size - 1] == '/'))
		return;
	else
		strcat(string, "/");
}

t_stack *stackFromList (t_list *list, t_stack *stack, char *folder)
{
	while (list){
		char *file_name = list->element->d_name;
		if (list->element->d_type == DT_DIR
				&& strcmp(file_name, ".") != 0
				&& strcmp (file_name, "..") != 0){
				char *new_path = NULL;   
				new_path = malloc(sizeof(*new_path) * (strlen(folder) + 1 + strlen(file_name) + 1));
				strcpy(new_path, folder);
				addSeparator(new_path);
				strcat(new_path, file_name);				
				stack = pushStack(stack, new_path);
				free(new_path);
				new_path = NULL;
		}
		list = list->next_element;
	}
	free(folder);
	folder = NULL;
	return stack;
}

void RecursiveLs(t_stack *stack)
{
	char *current_folder = NULL;
	t_list *current_list;
	t_list *begin_list;	
	while (stack->first_element){
		current_folder = malloc(sizeof(*current_folder) * strlen(stack->first_element->path_name) + 1);
		current_folder = strcpy (current_folder, stack->first_element->path_name);
		printf("%s:\n", current_folder);
		DIR *dir;
		dir = opendir(current_folder);
		if (dir == NULL){
		printf("ERROR OPENDIR %s\n", current_folder);
		return;
		}
		current_list = createList (dir);
		printSimpleLs (current_list);
		popStack (stack);
		printf("\n");
		current_list = reverseList (current_list);
		begin_list = current_list;
		stack = stackFromList (current_list, stack, current_folder);
		freeList(begin_list);
		begin_list = NULL;
		closedir(dir);
	}
	return;
}

t_list *optionList ()
{
	
}

void ftLsOption (t_list *entry_list, char **av, int ac, t_stack *stack)
{
	bool recu = false;
	t_list *option_list;
	
	
	int i;
	for (i = 1; i < ac; i++){
		if (strcmp(av[i], "-r") == 0)
			entry_list = reverseList(entry_list);
		if (strcmp(av[i], "-R") == 0)
			recu = true;
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
	DIR *dir;
	dir  = opendir(av[ac - 1]);
	if (dir == NULL){
		printf("ERROR OPENDIR %s\n", av [ac - 1]);
		return;
	}
	entry_list = createList(dir);
	if ((entry_list == NULL)){
		printf("DIRECTORY %s DOESN EXIST\n", av[ac - 1]);
		return;	
	}
	if ((ac > 2))
		ftLsOption(entry_list, av, ac, stack);
	else 
		printSimpleLs(entry_list);
	free(stack);
	stack = NULL;
	freeList (entry_list);
	closedir(dir);
}

int main (int argc, char **argv)
{	
	if (argc < 2)
		return 1;
	ftLs(argv, argc);
	return 0;
}