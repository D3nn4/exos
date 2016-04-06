#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

int ft_iterative_factorial(int nb)
{	
	if (nb > 0)
	{
		int res;
		int i;

		i = 1;
		res = 1;

		if (nb == 1)
		{
			return(1);
		}
		else
		{
			while (i <= nb)
			{
				res = res * i;
				i++;
			}
			return (res);
		}
	}
	else 
	{
		return (0);
	}
}

int main()
{
	ft_putnbr(ft_iterative_factorial(10));
	ft_putchar('\n');

	ft_putnbr(ft_iterative_factorial(11));
	ft_putchar('\n');

	ft_putnbr(ft_iterative_factorial(12));
	ft_putchar('\n');

	ft_putnbr(ft_iterative_factorial(13));
	ft_putchar('\n');

	ft_putnbr(ft_iterative_factorial(14));
	ft_putchar('\n');
	return 0;
}
