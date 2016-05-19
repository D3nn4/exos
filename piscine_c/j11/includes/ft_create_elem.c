#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
	t_list *new_list;
	new_list = malloc(sizeof(*new_list));
	if (new_list) {
		new_list->next = NULL;
		new_list->data = data;
	}
	return new_list;
}
