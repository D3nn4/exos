#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

void	ft_putstr(char *str)
{
	int index = 0;
	while (str[index] != '\0' )
	{
		ft_putchar(str[index]);
		index++;
	}
}

int		main ()
{
	char 	*str;
	str = "il etait une fois";

	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}