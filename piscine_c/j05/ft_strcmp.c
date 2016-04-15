#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"
#include "../ft_putnbr.c"


int ft_strcmp(char *s1, char *s2)
{
	int i;
	i = 0;
	while (s1[i] != '\0'){
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

	char str1[] = "abc";
	char str2[] = "abd";
	int result;

	result = ft_strcmp(str1, str2);
	if (result == 0)
		ft_putstr("str1 = str2");
	if (result == -1)
		ft_putstr("str1 < str2");
	if (result == 1)
		ft_putstr(" str1 > str2");
	ft_putchar('\n');


	return 0;
}