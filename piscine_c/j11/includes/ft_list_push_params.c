#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av)
{
	if (ac < 2)
		return NULL;
	t_list *begin_list = NULL;
	int i;
	for (i = 1; i < ac; i++){
		ft_list_push_front(&begin_list, av[i]);
	}
	return begin_list;
}

