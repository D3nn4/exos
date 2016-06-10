#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "header.h"

#define NBR_FORM 5

t_offset tabforms[NBR_FORM] = {
	{ 
		.x1 = 1,
		.y1 = 0,
		.x2 = 2,
		.y2 = 0,
		.x3 = 1,
		.y3 = 1,
		.str = "T form"
	},
	{
		.x1 = 1,
		.y1 = 0,
		.x2 = 0,
		.y2 = 1,
		.x3 = -1,
		.y3 = 1,
		.str = "Z form"
	},
	{
		.x1 = 1,
		.y1 = 0,
		.x2 = 0,
		.y2 = 1,
		.x3 = 1,
		.y3 = 1,
		.str = "O form"
	},
	{
		.x1 = 1,
		.y1 = 0,
		.x2 = 0,
		.y2 = 1,
		.x3 = 0,
		.y3 = 2,
		.str = "L form"
	},
	{
		.x1 = 0,
		.y1 = 1,
		.x2 = 0,
		.y2 = 2,
		.x3 = 0,
		.y3 = 3,
		.str = "I form"
	}
};

bool checkForm(char tab[4][4], t_offset offset)
{
	int x,y;
	for (y = 0; y < 4; y++){
		for (x = 0; x < 4; x++){
			if (tab[y][x] == '#'
				&& tab[y + offset.y1][x + offset.x1] == '#'
				&& tab[y + offset.y2][x + offset.x2] == '#'
				&& tab[y + offset.y3][x + offset.x3] == '#'){
				return true;
			}
		}
	}
	return false;
}

void checkAll(char tab[][4][4], int size)
{
	int i, j;
	bool valid_form;
	valid_form = false;
	for ( i = 0; i < size; i++){
		for (j = 0; j < NBR_FORM; j++){
			if(checkForm(tab[i], tabforms[j])){
				printf("%d tetriminos = %s\n",i, tabforms[j].str);
				valid_form = true;
			}
		}
		if (valid_form == false){
			printf("Fillit : wrong format of tetriminos list\n");
			return;
		}
		valid_form = false;
	}
}