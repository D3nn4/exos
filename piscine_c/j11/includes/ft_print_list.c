#include "ft_list.h"

void ft_print_list(t_list *liste)
{
	if (liste == NULL)
	    {
	        printf("empty list\n");
	        return;
	    }

	t_list *actuel = liste;

	while (actuel != NULL)
	    {
	        printf("%s -> ", (char*)actuel->data);
	        actuel = actuel->next;
	    }
	printf("NULL\n");
}