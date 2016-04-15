#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"

char *ft_strcat(char *dest, char *src)
{
	int i, j;
	i = 0;
	j = 0;
	while (dest[i] != '\0'){
		i++;
	}
	for (j; src[j] != '\0'; j++){
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

int main ()
{
	char dest[25] = "Hello";
	char str[] = "World !";

	ft_putstr(dest);
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');
	ft_strcat(dest, str);
	ft_putstr(dest);
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');

	return 0;
}