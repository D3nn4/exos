#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
  t_list *new_list = 0;
  t_list *list = *begin_list;
  while (list) {
      t_list *next_elem = list->next;
      list->next = new_list;
      new_list = list;
      list = next_elem;
  }
  *begin_list = new_list;
}



