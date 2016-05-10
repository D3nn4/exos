#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (begin_list == NULL)
		return NULL;
	if (ft_list_size(begin_list) < nbr)
		return NULL;
	t_list *to_find;
	to_find = begin_list;
	int i;
	for (i = 0; i < nbr; i++){
		to_find = to_find->next;
	}
	return to_find;
}