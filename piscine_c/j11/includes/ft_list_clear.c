#include "ft_list.h"

void ft_list_clear(t_list **begin_list)
{
	if(begin_list == NULL)
		return;
	t_list *to_clear;
	while((*begin_list)->next){
		to_clear = (*begin_list)->next;
		(*begin_list)->next = to_clear->next;
		free(to_clear);
	}
	free(begin_list);
}