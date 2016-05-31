#ifndef __FT_H__
#define __FT_H__
#include <stdlib.h>
#include <stdio.h>


typedef struct s_list
{
struct s_list *next;
void *data;
} t_list;



t_list *ft_create_elem(void *data);
void ft_list_push_back(t_list **begin_list, void *data);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
t_list *ft_list_last(t_list *begin_list);
t_list *ft_list_push_params(int ac, char **av);
t_list *ft_list_at(t_list *begin_list, unsigned int nbr);
void ft_list_reverse(t_list **begin_list);
void ft_print_elem(void *data);
void ft_list_foreach(t_list *begin_list, void (*f)(void *));
int ft_cmp_elem(void *elem1, void *elem2);
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
int ft_strcmp(char *s1, char *s2);
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

#endif