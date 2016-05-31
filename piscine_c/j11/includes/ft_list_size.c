#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return 0;
	int size;
	size = 0;
	t_list *current_elem;
	current_elem = begin_list;
	while (current_elem){
			current_elem = current_elem->next;
			size++;
	}

	return size;
}


