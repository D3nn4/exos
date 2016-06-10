#ifndef __HEADER_H__
#define __HEADER_H__
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_offset 
{
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	
	char *str;
} 			t_offset;

int pieces_nbr (int fd);
void getTetriTab (int fd, int size, char tab[][4][4]);
void print_tab (char tab[][4][4], int size);
void fillit (char *av);
bool checkForm(char tab[4][4], t_offset offset);
void checkAll(char tab[][4][4], int size);




#endif