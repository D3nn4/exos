#include "../lib/ft.h"

typedef struct new_pyramid
{
	int total_lines;
	int total_floors;
	int max_blank;

}				new_pyramid;

typedef struct new_line
{
	int nbr_stars;
	int nbr_blank;
	int num_line;
	int current_floor;
	int line_on_floor;

} 				c_line;


int height (int size)
{
	int base, height, i;
	base = 3;
	height = 3;
	if (size == 1)
		return base;
	for(i = 1; i < size; i++){
		height = height + base + i;
	}
	return height;
}

int widht_left_center (int size)
{
	int width,i, add_one, gap, total_gap;
	gap = 2;
	add_one = 0;
	total_gap = 0;
	for (i = 1; i < size; i++){
		total_gap = total_gap + gap;
		add_one++; 

		if (add_one == 2){
			gap++;
			add_one = 0;
		}
	}
	width = height(size) + total_gap - 1;
	return width;
}



void pyramid_creation(new_pyramid *pyramid, int size)
{
	pyramid->total_floors = size;
	pyramid->total_lines = height(size);
	pyramid->max_blank = widht_left_center(size);
}

void line_creation (new_pyramid *pyramid, c_line *current_line)
{
	current_line->nbr_stars = 1;
	current_line->nbr_blank = pyramid->max_blank;
	current_line->num_line = 1;
	current_line->current_floor = 1;
	current_line->line_on_floor = 3;
}

void next_ligne (c_line *current_line)
{
	current_line->nbr_stars += 2;
	current_line->nbr_blank -= 1;
	current_line->num_line++;
}

void print_line (c_line *current_line)
{
	int i, j;
	for (i = 0; i < current_line->nbr_blank; i++)
		ft_putchar(' ');
	ft_putchar('/');
	for (j = 0; j < current_line->nbr_stars; j++)
		ft_putchar('*');
	ft_putchar('\\');

}

void new_gap (c_line *current_line, int size_gap)
{
	current_line->nbr_stars += size_gap;
	current_line->nbr_blank -= (size_gap/2);
}

void write_floors (new_pyramid *pyramid, c_line *current_line)
{ 
	int i, j, add_to_gap, size_gap;
	add_to_gap = 0;
	size_gap = 4;

	for (i = 0; i < pyramid->total_floors; i++){
		for (j = 0; j < current_line->line_on_floor; j++){
			print_line(current_line);
			ft_putchar('\n');
			next_ligne(current_line);
			if (add_to_gap == 2)
			{
				size_gap += 2;
				add_to_gap = 0;
			}
		}
		new_gap(current_line, size_gap);
		add_to_gap++;
		current_line->line_on_floor++;

	}
	
}



void sastantua(int size)
{
	if (size == 0)
		return;
	new_pyramid pyramid;
	pyramid_creation(&pyramid, size);
	c_line current_line;
	line_creation(&pyramid,&current_line);
	write_floors(&pyramid, &current_line);	
}

int main(int argc, char **argv)
{
	int size;
	if (argc != 2)
		return 1;
	size = ft_atoi(argv[1]);
	sastantua(size);
	return 0;
}