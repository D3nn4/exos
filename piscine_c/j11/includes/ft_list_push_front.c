#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_element;
	new_element = ft_create_elem(data);
	if (begin_list && new_element){
		new_element->next = (*begin_list)->next;
		(*begin_list)->next = new_element;
	} 
}
