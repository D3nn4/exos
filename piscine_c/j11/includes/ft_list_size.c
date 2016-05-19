#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int size;
	size = 0;
	if (begin_list && begin_list->next){
		t_list *current_elem;
		current_elem = begin_list;
		while (current_elem->next)
			size++;
	}
	return size;
}