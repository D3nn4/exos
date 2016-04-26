#include "../lib/ft.h"

void		ft_putchar(char c);

void	write_door(int *i, int *width_door, int space, int s_door)
{
	int	position_key;

	position_key = s_door / 2;
	if ((space == position_key) && (*width_door == (s_door / 2) - 1)
		&& (s_door > 3))
		ft_putchar('$');
	else
		ft_putchar('|');
	*i = *i + 1;
	*width_door = *width_door + 1;
}
int		write_line(int line_nb, int space, int size_door)
{
	int	i;
	int	z;
	int	width_door;

	width_door = -size_door / 2;
	z = 0;
	i = 0;
	while (i < space)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	i = 0;
	while (i <= line_nb * 2)
	{
		while ((i == line_nb + width_door) && (space < size_door)
			&& (width_door <= size_door / 2))
			write_door(&i, &width_door, space, size_door);
		ft_putchar('*');
		i = i + 1;
	}
	ft_putchar('\\');
	ft_putchar('\n');
	return (space - 1);
}

void	print_pyramid(int space, int nb_jumps, int line_jump, int size_door)
{
	int	i;
	int	condition_inc_nb_jumps;
	int	var_jump;

	i = 0;
	var_jump = 4;
	condition_inc_nb_jumps = 1;
	while (space + 1)
	{
		if (i == line_jump)
		{
			i += nb_jumps;
			space -= nb_jumps;
			line_jump = i + var_jump;
			var_jump++;
			if (condition_inc_nb_jumps == 2)
			{
				nb_jumps++;
				condition_inc_nb_jumps = 0;
			}
			condition_inc_nb_jumps++;
		}
		space = write_line(i, space, size_door);
		i = i + 1;
	}
}

void	sastantua(int size)
{
	int	space;
	int	nb_jumps;
	int	line_jump;
	int	i;
	int	z;

	i = 1;
	z = 0;
	nb_jumps = 2;
	line_jump = 3;
	if (size > 0)
	{
		while (i <= size)
		{
			space = space + 6 + z;
			if (i > 1)
				z = z + 1;
			if ((i > 1) && (i % 2))
				z = z + 1;
			i++;
		}
		if (!(size % 2))
			size = size - 1;
		print_pyramid(space - 4, nb_jumps, line_jump, size);
	}
}

int main()
{
	sastantua(1);
	ft_putchar('\n');
	/*sastantua(2);
	ft_putchar('\n');
	sastantua(3);
	ft_putchar('\n');
	sastantua(4);
	ft_putchar('\n');
	sastantua(5);
	ft_putchar('\n');
	sastantua(6);
	ft_putchar('\n');
	sastantua(7);
	ft_putchar('\n');*/

	return 0;
}