#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

int ft_recursive_factorial(int nb)
{	
	if (nb > 0)
	{
		int res;
		if (nb == 1)
		{
			return(1);
		}
		else
		{
			res = (nb * ft_recursive_factorial(nb-1));
			return (res);
		}
	}
	else
	{
		return (0)
	}
}

int main()
{
	ft_putnbr(ft_recursive_factorial(10));
	ft_putchar('\n');

	ft_putnbr(ft_recursive_factorial(11));
	ft_putchar('\n');

	ft_putnbr(ft_recursive_factorial(12));
	ft_putchar('\n');

	ft_putnbr(ft_recursive_factorial(13));
	ft_putchar('\n');

	ft_putnbr(ft_recursive_factorial(14));
	ft_putchar('\n');
	return 0;
}
