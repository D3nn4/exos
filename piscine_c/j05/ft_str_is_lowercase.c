#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"
#include "../ft_putnbr.c"
#include "./ft_strstr.c"


int ft_str_is_lowercase(char *str)
{
	int i;
	i = 0;
	char numbers[] = "abcdefghijklmnopqrstuvwxyz";
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
	char string[] = "eelo";
	int res;
	
	res = ft_str_is_lowercase(string);
	if (res == 0)
		ft_putstr("Ne contient pas que des minuscules");
	if (res == 1)
		ft_putstr("Ne contient que des minuscules ou est une chaine vide");
	ft_putchar('\n');

	return 0;
}