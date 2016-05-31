#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
	if (begin_list == NULL)
		return NULL;
	t_list *element;
	element = begin_list;
	while (element->next) {
		element = element->next;
	}
	return element;
}
