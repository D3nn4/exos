#include <unistd.h>
#include "./ft_putchar.c"

void collea(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		return;
	}
	else
	{
		if (x == 1 && y == 1)
		{
			ft_putchar('o');
		}
		else
		{
			// 1ere ligne
			ft_putchar('o');
			if (x > 1)
			{
				int a;
				a = 1;
				for (a; a < x - 1; a++)
				{
					ft_putchar('-');
				}
				ft_putchar('o');
			}
			// lignes milieu
			if (y > 1)
			{
				ft_putchar('\n');
				int i;
				i = 1;
				for (i; i < y-1; i++)
				{
					// premiere colone
					ft_putchar('|');
					// colones milieu
					int j;
					j = 1;
					for (j; j < x - 1; j++)
					{
						ft_putchar(' ');
					}
					// dernière colone
					if (x > 1)
					{
						ft_putchar('|');	
					}
					ft_putchar('\n');
				}
				// derniere ligne
				ft_putchar('o');
				if (x > 1)
				{
					int b;
					b = 1;
					for (b; b < x - 1; b++)
					{
						ft_putchar('-');
					}
					ft_putchar('o');
				}
			}
		}
	}

}


void colle(int width, int height)
{
	int y = 0;
	while (y < height) {
		int x = 0;
		while (x < width) {
			if (x == 0 && y == 0
				|| x == width - 1 && y == height - 1
				|| x == 0 && y == height -1
				|| x == width -1 && y == 0)
				ft_putchar('o');
			else if (x == 0 || x == width -1)
				ft_putchar('|');
			else if (y == 0 || y == height -1)
				ft_putchar('-');
			else
				ft_putchar(' ');
			if (x == width -1)
				ft_putchar('\n');
			x++;
		}
		y++;
	}
}