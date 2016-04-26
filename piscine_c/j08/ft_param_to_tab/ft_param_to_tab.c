#include "../../lib/ft.h"
#include "ft_stock_par.h"
#include <stdlib.h>


struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
	int i;
	t_stock_par *array_struct;
	array_struct = malloc(sizeof(*array_struct) * (ac + 1));
	for (i = 0; i < ac; i++){
		array_struct[i].size_param = ft_strlen(av[i]);
		array_struct[i].str = av[i];
		char *tmp = malloc(sizeof(*tmp) * (ft_strlen(av[i]) + 1));
		ft_strcpy(tmp, av[i]);
		array_struct[i].copy = tmp;
		array_struct[i].tab = ft_split_whitespaces(av[i]);		 
	}
	array_struct[i].str = 0;
	return array_struct;
}

int main (int argc, char **argv)
{
	int i;
	t_stock_par *array;
	array = ft_param_to_tab(argc, argv);

	for (i = 0; i < argc; i++){
		ft_putstr("size_param : ");
		ft_putnbr(array[i].size_param);
		ft_putchar('\n');
		ft_putstr("adresse param ok : ");
		if (array[i].str == argv[i])
			ft_putstr("ok");
		ft_putchar('\n');
		ft_putstr("copy : ");
		ft_putstr(array[i].copy);
		ft_putchar('\n');
		ft_putstr("tab : ");
		ft_print_words_tables(array[i].tab);
		ft_putchar('\n');
	}
	return 0;
}