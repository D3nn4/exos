#include "../lib/ft.h"

int		ft_nb_tot_line(int *size)
{
	int no_floor;
	int nb_tot_line;

	no_floor = 1;
	nb_tot_line = 0;
	while (no_floor <= *size)
	{
		nb_tot_line += no_floor + 2;
		no_floor++;
	}
	return (nb_tot_line);
}

int		ft_nb_tot_space(int *size)
{
	int nb_floor_spec_space;
	int nb_tot_space;
	int no_floor;

	no_floor = 1;
	nb_floor_spec_space = 0;
	nb_tot_space = ft_nb_tot_line(size);
	while (no_floor <= *size)
	{
		nb_floor_spec_space = (2 + ((no_floor + 2) / 2) * 2) / 2;
		nb_tot_space += nb_floor_spec_space - 1;
		no_floor++;
	}
	nb_tot_space -= 1;
	return (nb_tot_space);
}

void	sastantua(int size)
{
	int no_floor;
	int no_line_floor;
	int nb_line_floor;
	int nb_space;
	int nb_space_to_do;
	int nb_star;
	int nb_star_to_do;
	int nb_pipe_to_do;
	int size_door;
	int no_door_line;
	int no_door_handle_line;

	no_floor = 1;
	nb_space = ft_nb_tot_space(&size);
	nb_star = -1;
	size_door = (size - 1) / 2 * 2 + 1;
	while (no_floor <= size)
	{
		no_line_floor = 1;
		nb_line_floor = no_floor + 2;
		nb_space -= ((2 + ((no_floor + 2) / 2) * 2) / 2) - 1;
		nb_star += ((2 + ((no_floor + 2) / 2)) * 2) - 4;
		while (no_line_floor <= nb_line_floor)
		{
			nb_space_to_do = nb_space;
			while (nb_space_to_do > 0)
			{
				ft_putchar(' ');
				nb_space_to_do--;
			}
			nb_space--;
			ft_putchar(47);
			nb_star_to_do = nb_star;
			if (no_floor != size || (no_floor == size && no_line_floor < no_door_line))
			{
				while (nb_star_to_do > 0)
				{
					ft_putchar('*');
					nb_star_to_do--;
				}
			}
			else
			{
				if (no_floor == size && no_line_floor >= no_door_line)
				{
					nb_star_to_do = (nb_star - size_door) / 2;
					while (nb_star_to_do > 0)
					{
						ft_putchar('*');
						nb_star_to_do--;
					}
					if (no_line_floor == no_door_handle_line && size > 4)
						nb_pipe_to_do = size_door -2;
					else
						nb_pipe_to_do = size_door;
					while (nb_pipe_to_do > 0)
					{
						ft_putchar('|');
						nb_pipe_to_do--;
					}
					if (no_line_floor == no_door_handle_line && size > 4)
					{
						ft_putchar('$');
						ft_putchar('|');
					}
					nb_star_to_do = (nb_star - size_door) / 2;
					while (nb_star_to_do > 0)
					{
						ft_putchar('*');
						nb_star_to_do--;
					}
				}
			}
			ft_putchar(92);
			nb_star += 2;
			no_line_floor++;
			ft_putchar('\n');
			no_door_line = nb_line_floor - size_door + 1;
			no_door_handle_line = no_door_line + size_door / 2;
		}
		no_floor++;
	}
}

int main()
{
	sastantua(1);
	ft_putchar('\n');
	sastantua(2);
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
	ft_putchar('\n');

	return 0;
}