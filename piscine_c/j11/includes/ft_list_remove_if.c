#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL){
		printf("Empty list.\n");
		return;
	}
	t_list *list;
	list = *begin_list;
	t_list *previous_elem = NULL;
	t_list *to_delete = NULL;
	while (list){
		if (cmp(list->data, data_ref) == 0 && previous_elem == NULL){
			to_delete = list;
			list = list->next;
			to_delete->next = NULL;
			free(to_delete);
		}
		else if (cmp(list->data, data_ref) == 0 && previous_elem){
			to_delete = list;
			previous_elem->next = list->next;
			list = list->next;

		}
		
	}

}
void ft_remove_elem(t_list *to_delete)
{
	to_delete->next = NULL;
	free(to_delete);
}