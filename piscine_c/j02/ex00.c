#include <unistd.h>
void 	ft_print_alphabet()
{
	char c;
	int i;

	c = 'a';
	i = 0;
	while (i < 26)
		{
			write(1, &c, 1);;
			i++;
			c++;	
		}
}

int 	main()
{
	ft_print_alphabet();
	write(1, "\n", 1);
	return (0);
}