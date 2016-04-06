#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

int	ft_atoi(char *str)
{
	int	nb;
	int index = 0;
	int res = 0;
		
	while (str[index] != '\0' )
	{
		res = res*10;
		nb = str[index] - '0';
		res = (res + nb);
		index++;
	}	
	return (res);			
}

int		main ()
{
	
	char 	*str;
	str = "123";
	int resultat;

	resultat = ft_atoi(str);
	if (123 == resultat)
	{
		ft_putchar('k');
	}
	ft_putchar('\n');
	return (0);
}