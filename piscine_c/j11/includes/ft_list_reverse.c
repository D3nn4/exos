#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
	if ( begin_list == NULL)
		return;
	t_list *new_begin_list;
	new_begin_list->next = NULL;
	t_list *new_current;
	while((*begin_list)->next != NULL){
		t_list *current_element;
		current_element = *begin_list;
		while(current_element->next != NULL){
			current_element = current_element->next;
		}
		if (new_begin_list->next){
			new_current = current_element->next;
			current_element->next = NULL;
		}
		else {
			new_begin_list->next = current_element->next;
			new_current = current_element->next;
			current_element->next = NULL;
		}
	}
	new_current->next = NULL;
	(*begin_list)->next = new_begin_list->next;
}