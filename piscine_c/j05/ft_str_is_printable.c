#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"
#include "../ft_putnbr.c"
#include "./ft_strstr.c"


int ft_str_is_printable(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0'){
		if ( " " <= str[i] && str[i] <= "~")
				i++;
		else 
			return 0;	
	}
	return 1;
}

int main ()
{
	char string[] = "TEST";
	int res;
	
	res = ft_str_is_printable(string);
	if (res == 0)
		ft_putstr("N'est pas imprimable");
	if (res == 1)
		ft_putstr("Est imprimable");
	ft_putchar('\n');

	return 0;
}