#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_element;
	t_list *list;
	list = *begin_list;
	new_element = ft_create_elem(data);
	if (list && new_element){
		new_element->next = list;
		list = new_element;
	} 
	if (list == NULL && new_element){
		list = new_element;
	}
	*begin_list = list;
}
