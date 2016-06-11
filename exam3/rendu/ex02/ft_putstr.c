#include <unistd.h>

void ft_putstr(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++){
		write(1, &str[i], 1);
	}
}

int main()
{
	char *str;
	str = "Hello World";
	ft_putstr(str);
	write(1, "\n", 1);

	return 0;
}