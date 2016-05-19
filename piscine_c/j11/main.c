#include "./includes/ft_list.h"

int main()
{
	t_list *liste = ft_create_elem("toto");
    int size;

	ft_list_push_front(&liste, "tata");
	ft_list_push_front(&liste, "titi");
    ft_list_push_back(&liste, "last");
    ft_list_push_front(&liste, "first");

    size = ft_list_size(liste);

    //printf("%d\n", size);

  if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    t_list *actuel = liste->next;

    while (actuel != NULL)
    {
        printf("%s -> ", actuel->data);
        actuel = actuel->next;
    }
    printf("NULL\n");

}