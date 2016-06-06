#include "./header.h"
#include <stdbool.h>

/*
void check_colle00 (char *buf, int widht, int height)
{

}

void check_colle01 (char *buf, int widht, int height)
{
	
}

void check_colle02 (char *buf, int widht, int height)
{
	
}

bool check_bord234 (char **tab2D, int widht, int height)
{
	int x, y;
	for (y = 0; y < height; y++){
		for (x = 0; x < widht; x++){
			if (y == 0 && x > 0 && x < widht - 1 && tab2D[y][x] != 'B')
				return false;
			if (y == height - 1 && x > 0 && x < widht - 1 && tab2D[y][x] != 'B')
				return false;
			if (x == 0 && y > 0 && y < height - 1 && tab2D[y][x] != 'B')
				return false;
			if (x == widht - 1 && y > 0 && y < height - 1 && tab2D[y][x] != 'B')
				return false;
		}
	}
	return true;
}

bool check_inside (char **tab2D, int widht, int height)
{
	int x, y;
	for (y = 1; y < height - 1; y++){
		for (x = 1; x < widht - 1; x++){
			if (tab2D[y][x] != ' ')
				return false;
		}
	}
	return true;
}

void check_colle234 (char **tab2D, int widht, int height)
{
	if (widht == 1 && height == 1 && tab2D[0][0] == 'A'){
		printf("[colle-02] [%d] [%d] || ", widht, height);
		printf("[colle-03] [%d] [%d] || ", widht, height);
		printf("[colle-04] [%d] [%d]\n", widht, height);
		return;
	}
	if (check_bord234(tab2D, widht, height)){
		if (check_inside(tab2D, widht, height)){
			if (tab2D[0][0] == 'A' && tab2D[height - 1][0] == 'A'){
				if (tab2D[0][widht - 1] == 'C' && tab2D[height - 1][widht - 1] == 'C')
					printf("[colle-03] [%d] [%d]\n", widht, height);
			}
			if (tab2D[0][0] == 'A' && tab2D[height - 1][0] == 'C'){
				if (tab2D[0][widht - 1] == 'C' && tab2D[height - 1][widht - 1] == 'A')
					printf("[colle-04] [%d] [%d]\n", widht, height);
			}
			if (tab2D[0][0] == 'A' && tab2D[height - 1][0] == 'C'){
				if (tab2D[0][widht - 1] == 'A' && tab2D[height - 1][widht - 1] == 'C')
					printf("[colle-02] [%d] [%d]\n", widht, height);
			}
		}
	}
}

*/