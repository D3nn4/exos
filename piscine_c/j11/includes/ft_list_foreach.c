#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (begin_list == NULL){
		printf("Empty list.\n");
		return;
	}
	t_list *list;
	list = begin_list;
	while (list){
		f(list->data);
		list = list->next;
	}
}

