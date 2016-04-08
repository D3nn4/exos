#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"


char *ft_strcpy(char *dest, char *src)
{
	int index;
	index = 0;

	while ((src[index]) != '\0'){
		dest[index] = src[index];
		index++;
	}
	dest[index] = src[index];
	return dest;
}


int main ()
{
	char copy[] = "aaaaaaa";
	char string[] = "Hello";

	ft_putstr(string);
	ft_putchar('\n');
	ft_putstr(copy);
	ft_putchar('\n');
	ft_strcpy(copy, string);
	ft_putstr(copy);
	ft_putchar('\n');

	return (0);
}