#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"
#include "../ft_putnbr.c"


char *ft_strlowcase(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0'){
		if (str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return str;
}

int main ()
{
	char string[] = "Hello";
	
	ft_putstr(string);
	ft_putchar('\n');
	ft_strlowcase(string);
	ft_putstr(string);
	ft_putchar('\n');

	return 0;
}