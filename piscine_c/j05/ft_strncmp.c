#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"
#include "../ft_putnbr.c"


int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;
	i = 0;
	while (s1[i] != '\0' && i < n){
		if (s1[i] > s2[i])
			return 1; 
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return 0;
}

int main ()
{

	char str1[] = "acc";
	char str2[] = "abd";
	int result, n;
	n = 2;

	result = ft_strncmp(str1, str2, n);
	if (result == 0)
		ft_putstr("str1 = str2");
	if (result == -1)
		ft_putstr("str1 < str2");
	if (result == 1)
		ft_putstr(" str1 > str2");
	ft_putchar('\n');


	return 0;
}