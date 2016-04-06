#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

void	ft_div_mod(int a, int b, int *divi, int *mod)
{
	*divi = a / b;
	*mod = a % b;
}

int		main ()
{
	int		res;
	int 	reste;
	int		*ptr;
	int		*ptr2;

	ptr = &res;
	ptr2 = &reste;

	ft_div_mod(3, 2, ptr, ptr2);
	ft_putnbr(*ptr);
	ft_putchar('\n');
	ft_putnbr(*ptr2);
	ft_putchar('\n');
	return (0);
}