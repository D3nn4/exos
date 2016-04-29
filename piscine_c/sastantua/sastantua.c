#include "../lib/ft.h"

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

int first_pyramid (int blank)
{
	int i, line, stars;
	line = 0;
	stars = 1;
	while (line < 3){
		for (i = 0; i < blank; i++){
			ft_putchar(' ');
		}
		ft_putchar('/');
		for (i = 0; i < stars; i++){
			ft_putchar('*');
		}
		ft_putchar('\\');
		ft_putchar('\n');
		stars += 2;
		line++;
		if(blank != 0)
			blank--;
	}
	blank -= 2;
	return blank;
}


void write_lines (int size, int blank)
{
	int line, i, j, k, l, nb_stars, gap, new_gap;
	line = height(size) - 3;
	gap = 4;
	nb_stars = 7 + gap;
	new_gap = 4;
	l = 0;

	for (i = 0; i < line; i++){
		l++;
		for (j = 0; j < blank; j++)
			ft_putchar(' ');
		ft_putchar('/');
		for (k = 0; k < nb_stars; k++){
			ft_putchar('*');
		}
		nb_stars += 2;
		ft_putchar('\\');
		ft_putchar('\n');
		blank--;
		
		if (l == new_gap ){
			gap += 2;
			new_gap++;
			nb_stars += gap;
			blank -= (gap/2);
			l = 1;
		}
	}
}



void sastantua(int size)
{
	if (size == 0)
		return;
	int blank;
	blank = first_pyramid(widht_left_center(size));
	if (blank == 0)
		return;
	write_lines(size, blank);
}

int main()
{
	sastantua(5);
	return 0;
}
