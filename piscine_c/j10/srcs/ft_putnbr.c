void ft_putnbr(int nb)
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

void ft_putnbra(int nb) 
{
	if (nb == 0)
		return ;
	ft_putnbr(nb / 10);
	ft_putchar( (nb % 10) + '0'); 
}

