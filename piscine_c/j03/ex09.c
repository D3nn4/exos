#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

void	ft_sort_integer_table(int *tab, int size)
{
	int index = 0;
	if (size < 2)
	{
		return;
	}
	
	while (index < size - 1)
	{
		if (tab[index] < tab[index + 1])
		{
			index++;			
		}
		else
		{
			int a = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = a;
			index = 0;
		}	
	}
}

int		main ()
{
	int tab[5];

	tab[0] = 45;
	tab[1] = 39;
	tab[2] = 7;
	tab[3] = 71;
	tab[4] = 3;

	ft_sort_integer_table(tab, 5);

	int i;
	for (i = 0; i < 5; i++ )
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
	}
	

	
	return (0);
}