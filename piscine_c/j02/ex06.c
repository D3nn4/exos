#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(nb)
{
	if (nb < 0){
		nb = nb * -1;
		ft_putchar('-');

	}
	int mult = 10;
	int res = nb;
	int last_nb = nb;
	while (res > 9)
	{
		res = nb / mult;
		mult *= 10;
	}
	
	while (mult > 10)
	{
		mult /= 10;
		int chiffre = last_nb / mult;
		last_nb = last_nb % mult;
		ft_putchar(chiffre + '0');	
	}

	int units = nb % 10;
	ft_putchar(units + '0');
}

int 	main()
{
	ft_putnbr(-123456789);
	write(1, "\n", 1);
	return (0);
}



