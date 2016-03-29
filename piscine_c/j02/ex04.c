#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void ft_print_comb()
{
	int cents = 0;
	int tens = 0;
	int units = 0;
	while (cents <= 9)
	{
		while(tens <=9)
		{
			while(units <= 9)
			{

				if (cents < tens && tens < units )
				{
				ft_putchar(cents + '0'); 
				ft_putchar(tens + '0'); 
				ft_putchar(units + '0'); 
				ft_putchar('\n');
				units++;
				}
				else 
				{
					units++;
				}
			}
			units = 0;
			tens++;
		
		}
		tens = 0;
		cents++;
	}
}


int main ()
{
	ft_print_comb();
	return (0);
}

