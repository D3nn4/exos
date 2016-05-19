#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *element;
	element = *begin_list;
	if(element != NULL)
	{
		while (element->next) {
			element = element->next;
		}
		element->next = ft_create_elem(data);
	}
}