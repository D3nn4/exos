#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
	t_list *element;
	element = begin_list;
	if(element != NULL)
	{
		while (element->next) {
			element = element->next;
		}
		return element;
	}
}
