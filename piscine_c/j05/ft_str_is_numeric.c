#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"
#include "../ft_putnbr.c"
#include "./ft_strstr.c"


int ft_str_is_numeric(char *str)
{
	int i;
	i = 0;
	char numbers[] = "0123456789";
	while (str[i] != '\0'){
		if (ft_strstr(numbers, &str[i]) != NULL)
			i++;
		else 
			return 0;	
	}
	return 1;
}

int main ()
{
	char string[] = "42";
	int res;
	
	res = ft_str_is_numeric(string);
	if (res == 0)
		ft_putstr("Ne contient pas que des chiffres");
	if (res == 1)
		ft_putstr("Ne contient que des chiffres ou est une chaine vide");
	ft_putchar('\n');

	return 0;
}