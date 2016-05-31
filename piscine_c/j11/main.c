#include "./includes/ft_list.h"

int main(int argc, char **argv)
{
	t_list *liste = NULL;
    int size;
    int a, b;
    a = 2;
    b = 10; 
    
    //creation liste
    ft_list_push_front(&liste, "toto");
	ft_list_push_front(&liste, "tata");
	ft_list_push_front(&liste, "titi");
    ft_list_push_back(&liste, "last");
    ft_list_push_front(&liste, "first");
    ft_print_list(liste);

    // taille liste
    size = ft_list_size(liste);
    printf("Il y a %d elements\n", size);

    // print list
    ft_print_list(liste);
    // elem dans liste
    t_list *elem_at = ft_list_at(liste, a);
    printf("Le %deme element est %s\n", a, (char*)elem_at->data);

    t_list *elem_out = ft_list_at(liste, b);
    if(elem_out)
        printf("Le %deme element est %s\n", b,(char*)elem_out->data);
    else
        printf("no %dth element\n", b);

    t_list *last_elem = ft_list_last(liste);
    printf("%s\n", (char*)last_elem->data);

    // liste depuis argv
    t_list *new_list = ft_list_push_params(argc, argv);
    ft_print_list(new_list);

    // inversion liste
    t_list *mylist = ft_create_elem("wut");
    ft_list_push_front(&mylist, "1");
    ft_list_push_front(&mylist, "2");
    ft_list_push_front(&mylist, "3");
    ft_print_list(mylist);
    ft_list_reverse(&mylist);
    ft_print_list(mylist);
 

    printf("coucou, delete time !\n");
    ft_list_clear(&liste);
    ft_print_list(liste);
    ft_list_clear(&new_list);
    ft_print_list(new_list);

    printf("************ft_list_foreach***************\n");
    void (*f)(void*);
    f = &ft_print_elem;
    ft_list_foreach(mylist,f);

    printf("************ft_list_foreach_if************\n");
    int (*cmp)();
    cmp = &ft_cmp_elem;
    ft_list_foreach_if(mylist, f, "2", cmp);

    printf("************ft_list_find******************\n");
    t_list *find_list;
    find_list = ft_list_find(mylist, "2", cmp);
    ft_print_list(find_list);

    return 0;
}