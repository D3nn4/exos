#include <stdio.h>
#include "./header.h"
#include <stdbool.h>

	t_letters tabcolle[2] = {
	{ // colle 03
	.corner_up_right = 'C', 
	.corner_up_left = 'A', 
	.corner_down_right = 'C',
	.corner_down_left= 'A',
	.border_hor = 'B',
	.border_ver = 'B',
	.inside = ' ',
	.str = "colle-03"},
	{ //colle 04
	.corner_up_right = 'C', 
	.corner_up_left = 'A', 
	.corner_down_right = 'A',
	.corner_down_left= 'C',
	.border_hor = 'B',
	.border_ver = 'B',
	.inside = ' ',
	.str = "colle-04"}
};


void checkall(char **tab2D, int widht, int height) 
{
	int i;
	bool previous = false;
	for (i = 0; i < 2; i++){
		if (check_colle(tab2D, widht, height, tabcolle[i])){
			if (previous){
				printf(" || ");
				previous = false;
			}
			printf("[%s] [%d] [%d]",tabcolle[i].str, widht, height);
			previous = true;
		}
	}
	printf("\n");
}

bool check_sides ( char **tab2D, int widht, int height, t_letters colle)
{
	int x, y;
	for (y = 0; y < height; y++){
		for (x = 0; x < widht; x++){
			if ((y == 0 && x > 0 && x < widht - 1 && tab2D[y][x] != colle.border_hor)){
				printf("%c\n%c\n", colle.border_hor, tab2D[y][x] );
					printf("false check sides widht\n");
					return false;
			}
			if (height > 0){
				if ((x == 0 && y > 0 && y < height - 1 && tab2D[y][x] != colle.border_ver)
					&& (x == widht - 1 && y > 0 && y < height - 1 && tab2D[y][x] != colle.border_ver)
					&& (y == height - 1 && x > 0 && x < widht - 1 && tab2D[y][x] != colle.border_hor)){
					printf("false check sides height\n");
					return false;
				}
			}
		}
	}
	return true;
}

bool check_corners ( char **tab2D, int widht, int height, t_letters colle)
{
	if (widht > 0){
		printf("tab2D[height - 1][widht - 1]%c colle.corner_down_right : %c\n", tab2D[height - 1][widht - 1], colle.corner_down_right);
		printf("tab2D[0][widht - 1]%c colle.corner_up_right : %c\n", tab2D[0][widht - 1], colle.corner_up_right);

		if ((tab2D[height - 1][widht - 1] != colle.corner_down_right)
			&& (tab2D[0][widht - 1] != colle.corner_up_right)){
			printf("false check corners widht > 0\n");
			return false;
		}
	}
	if (height > 0){
		if ((tab2D[height - 1][0] != colle.corner_down_left)
			&& (tab2D[0][0] != colle.corner_up_left)){
			printf("false check corners height > 0\n");
			return false;
		}
	}
	return true;
}

bool check_inside ( char **tab2D, int widht, int height, t_letters colle)
{
	int x, y;
	for (y = 0; y < height; y++){
		for (x = 0; x < widht; x++){
			if (y > 1 && x > 1 
				&& (x < widht - 1) && (y < height - 1) 
				&& (tab2D[y][x] != colle.inside)){
				printf("false check inside\n");
				return false;
			}
		}
	}
	return true;
}

bool check_colle(char **tab2D, int widht, int height, t_letters colle)
{
	if ( widht == 1 && height == 1){
		if (tab2D[0][0] == colle.corner_up_left)
			return true;
	}
	if (check_corners(tab2D, widht,height, colle)
				&& check_sides(tab2D, widht, height, colle)
				&& check_inside(tab2D, widht, height, colle))
				return true;
	return false;
}
