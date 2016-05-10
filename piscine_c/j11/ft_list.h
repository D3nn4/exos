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

#endif