#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	int index;
	index = 0;

	while (index < n && src[index] != '\0'){
		dest[index] = src[index];
		index++;
	}
	while (index < n){
		dest[index] = '\0';
		index++;
	}
	return dest;
}

int main ()
{

	
	char str1[] = "Hello";
	char str2[] = "Goodbye all";

	ft_putstr(str1);
	ft_putchar('\n');
	ft_putstr(str2);
	ft_putchar('\n');
	ft_putstr("__________");
	ft_putchar('\n');
	ft_strncpy(str2, str1, 7);
	ft_putstr(str1);
	ft_putchar('\n');
	ft_putstr(str2);
	ft_putchar('\n');

	return (0);
}