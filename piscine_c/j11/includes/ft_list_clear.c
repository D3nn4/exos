#include "ft_list.h"

void ft_list_clear(t_list **begin_list)
{
	if(begin_list == NULL){
		printf("empty list\n");
		return;
	}
	t_list *to_clear;
	t_list *list;
	list = *begin_list;
	while(list){
		to_clear = list;
		list = list->next;
		free(to_clear);
	}
	*begin_list = NULL;
}