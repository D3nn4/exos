#include "header.h"
#include "ft.h"

t_stack *popStack (t_stack *stack)
{	
	t_element *to_remove;
	to_remove = stack->first_element;
	stack->first_element = stack->first_element->next;
	free(to_remove->path_name);
	to_remove->next = NULL;
	free(to_remove);
	to_remove = NULL;
	return stack;


}

t_stack *pushStack (t_stack *stack, char *folder_name)
{	
	t_element *current_element;
	current_element = malloc(sizeof(*current_element));
	current_element->path_name = malloc(sizeof(folder_name) * strlen(folder_name) + 1);
	current_element->path_name = strcpy(current_element->path_name, folder_name);
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
	origin_folder->path_name = malloc(sizeof(*av) * strlen(av) + 1);
	origin_folder->path_name = strcpy(origin_folder->path_name, av);
	stack->first_element = origin_folder;
	return stack;
}

