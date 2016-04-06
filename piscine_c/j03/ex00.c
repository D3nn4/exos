#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int		main ()
{
	int nb;
	int *ptr;
	ptr = &nb;

	ft_ft(ptr);

	ft_putnbr(nb);
	ft_putchar('\n');
	return (0);
}