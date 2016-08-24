#include "header.h"
#include "ft.h"

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

t_stack *popStack (t_stack *stack)
{	
	t_element *to_remove;
	to_remove = stack->first_element;
	stack->first_element = stack->first_element->next;
	free(to_remove->name);
	to_remove->next = NULL;
	free(to_remove);
	to_remove = NULL;
	return stack;
}

t_stack *pushStack (t_stack *stack, char *folder_name)
{	
	t_element *current_element;
	current_element = malloc(sizeof(*current_element));
	current_element->name = malloc(sizeof(folder_name) * strlen(folder_name) + 1);
	current_element->name = strcpy(current_element->name, folder_name);
	current_element->next = stack->first_element;
	stack->first_element = current_element;

	return stack;
}

t_stack *createStack (char *av)
{
	t_stack *stack;
	stack = malloc(sizeof(*stack));
	stack->first_element = NULL;
	t_element *origin_folder;
	origin_folder = malloc(sizeof(*origin_folder));
	origin_folder->next = NULL;
	origin_folder->name = malloc(sizeof(*av) * strlen(av) + 1);
	origin_folder->name = strcpy(origin_folder->name, av);
	stack->first_element = origin_folder;
	return stack;
}

