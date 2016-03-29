#include <unistd.h>
void	ft_print_numbers()
{
	char c;
	int i;

	c = '0';
	i = 0;
	while (i < 10)
		{
			write(1, &c, 1);
			i++;
			c++;	
		}
}

int 	main()
{
	ft_print_numbers();
	write(1, "\n", 1);
	return (0);
}