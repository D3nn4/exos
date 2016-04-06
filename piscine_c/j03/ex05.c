#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putnbr.c"

void	ft_strlen(char *str)
{
	int index = 0;
	while (str[index] != '\0' )
	{
		index++;
	}
	ft_putnbr(index);
}

int		main ()
{
	char 	*str;
	str = "il etait une fois";

	ft_strlen(str);

	ft_putchar('\n');
	return (0);
}