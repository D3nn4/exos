#ifndef __HEADER_H__
#define __HEADER_H__
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

enum tetrisType 
{
	LEFT_L,
	//RIGHT_L,
	LINE,
	T_FORM,
	SQUARE,
	//LEFT_Z,
	RIGHT_Z
};

typedef struct s_offset 
{	
	int x;
	int y;
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	enum tetrisType form;
	char *str;
} 			t_offset;

int pieces_nbr (int fd);
void getTetriTab (int fd, int size, char tab[][4][4]);
void print_tab (char tab[][4][4], int size);
void fillit (char *av);
bool checkForm(char tab[4][4], t_offset offset, t_offset *tab_form);
void checkAll(char tab[][4][4], int size, t_offset *tab_form);




#endif