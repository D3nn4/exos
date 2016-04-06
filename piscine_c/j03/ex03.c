#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

void	ft_div_mod(int *a, int *b)
{
	int divi;
	int mod;

	divi = *a / *b;
	mod = *a % *b;

	*a = divi;
	*b = mod;
}

int		main ()
{
	int		a;
	int 	b;

	a = 42;
	b = 2;

	ft_div_mod(&a, &b);
	ft_putnbr(a);
	ft_putchar('\n');
	ft_putnbr(b);
	ft_putchar('\n');
	return (0);
}