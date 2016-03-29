#include <unistd.h>
void	ft_print_reverse_alphabet()
{
	char c;
	int i;

	c = 'z';
	i = 0;
	while (i < 26)
		{
			write(1, &c, 1);
			i++;
			c--;	
		}
}

int 	main()
{
	ft_print_reverse_alphabet();
	write(1, "\n", 1);
	return (0);
}