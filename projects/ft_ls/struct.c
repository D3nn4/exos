#include "header.h"
#include "ft.h"

t_data *createStruct ()
{
	t_data *struct_data;
	struct_data = malloc (sizeof (*struct_data));
	struct_data->option_list = NULL;
	struct_data->directory_list = NULL;
	return struct_data;
}

t_element *pushFrontList (char *element_name, t_element *first_element)
{
	t_element *new_element;
	new_element = malloc (sizeof (*new_element));
	new_element->name = malloc(sizeof(*element_name) * strlen (element_name) + 1);
	strcpy (new_element->name, element_name);
	new_element->next = first_element;
	return new_element;
}

t_element *pullFromList (t_element *element_list, char *element_name)
{	
	if (element_list->next == NULL 
		&& strcmp (element_list->name, element_name) == 0){
		element_list = NULL;
	}
	else if (element_list != NULL){
		t_element *to_remove = NULL;
		t_element *previous_element = NULL;
		t_element *current_element = element_list;
		while (strcmp (element_name, current_element->name) != 0){
			previous_element = current_element;
			current_element = current_element->next;
		}
		to_remove = current_element;
		if (previous_element == NULL)
			element_list = current_element->next;
		else
			previous_element->next = current_element->next;
		free(to_remove->name);
		to_remove->next = NULL;
		free(to_remove);
		to_remove = NULL;
		previous_element = NULL;
		current_element = NULL;
	}
	return element_list;
}

/*
typedef struct 	s_list {
	struct dirent *element;
	struct s_list *next_element;
}				t_list;

typedef struct  s_element {
	char *name;
	struct s_element *next;

}				t_element;

typedef struct  s_stack {
	t_element *first_element;
}				t_stack;

typedef struct s_data {
	t_element *option_list;
	t_element *directory_list;
}				t_data;
*/