#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"
#include "../ft_putnbr.c"
#include "./ft_strstr.c"

char *ft_strcapitalize(char *str)
{
	int i;
	i = 1;
	const char all[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	const char letters[] = "abcdefghijklmnopqrstuvwxyz";
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[i] != '\0'){
		if (ft_strstr(all, &str[i-1]) == NULL && 
			ft_strstr(letters, &str[i]) != NULL){
			str[i] = str[i] - 32;
		}
		i++;	
	}
	return str;
}

int main ()
{
	char string[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	
	ft_putstr(string);
	ft_putchar('\n');
	ft_strcapitalize(string);
	ft_putstr(string);
	ft_putchar('\n');

	return 0;
}

