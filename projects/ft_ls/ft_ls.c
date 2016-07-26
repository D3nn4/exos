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

void  RecursiveLs(t_stack *stack)
{
	char *current_folder = NULL;
	t_list *current_list;
	current_list = malloc(sizeof(*current_list));	
	while (stack->first_element){
		current_folder = malloc(sizeof(*current_folder) * strlen(stack->first_element->path_name) + 1);
		current_folder = strcpy (current_folder, stack->first_element->path_name);
		printf("%s:\n", current_folder);
		current_list = createList (current_folder);
		printSimpleLs (current_list);

		popStack (stack);
		printf("\n");
		while (current_list){
			char *file_name = current_list->element->d_name;
			if (current_list->element->d_type == DT_DIR
				&& strcmp(file_name, ".") != 0
				&& strcmp (file_name, "..") != 0){
				
				char *new_path = NULL;   
				new_path = malloc(sizeof(*new_path) * (strlen(current_folder) + 1 + strlen(file_name) + 1));
				strcpy(new_path, current_folder);
				strcat(new_path, "/");
				strcat(new_path, file_name);				
				stack = pushStack(stack, new_path);
			}

			current_list = current_list->next_element;
		}
	}
	free(current_folder);
	free(current_list);
	current_folder = NULL;
	current_list = NULL;
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
	if ((entry_list == NULL)){
		printf("DIRECTORY %s DOESN EXIST\n", av[ac - 1]);
		return;	
	}
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