#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

void	ft_swap(int *a, int *b)
{
	int nb1;
	int nb2;

	nb1 = *a;
	nb2 = *b;

	*a = nb2;
	*b = nb1;
}

int		main ()
{
	int		a;
	int 	b;

	a = 42;
	b = 2;
	
	ft_putnbr(a);
	ft_putchar('\n');
	ft_putnbr(b);
	ft_putchar('\n');

	ft_swap(&a, &b);
	ft_putnbr(a);
	ft_putchar('\n');
	ft_putnbr(b);
	ft_putchar('\n');
	return (0);
}