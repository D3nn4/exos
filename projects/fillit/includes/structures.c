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
		.form = T_FORM,
		.str = "T form"
	},
	{
		.x1 = 1,
		.y1 = 0,
		.x2 = 0,
		.y2 = 1,
		.x3 = -1,
		.y3 = 1,
		.form = RIGHT_Z,
		.str = "Z form"
	},
	{
		.x1 = 1,
		.y1 = 0,
		.x2 = 0,
		.y2 = 1,
		.x3 = 1,
		.y3 = 1,
		.form = SQUARE,
		.str = "O form"
	},
	{
		.x1 = 1,
		.y1 = 0,
		.x2 = 0,
		.y2 = 1,
		.x3 = 0,
		.y3 = 2,
		.form = LEFT_L,
		.str = "L form"
	},
	{
		.x1 = 0,
		.y1 = 1,
		.x2 = 0,
		.y2 = 2,
		.x3 = 0,
		.y3 = 3,
		.form = LINE,
		.str = "I form"
	}
};

bool checkForm(char tab[4][4], t_offset offset,t_offset *tab_form)
{
	int x,y;
	
	for (y = 0; y < 4; y++){
		for (x = 0; x < 4; x++){

			if (tab[y][x] == '#'
				&& (y + offset.y1 < 4) && (x + offset.x1 < 4)
				&& (y + offset.y2 < 4) && (x + offset.x2 < 4) 
				&& (y + offset.y3 < 4) && (x + offset.x3 < 4)){
				if	(tab[y + offset.y1][x + offset.x1] == '#'
					&& tab[y + offset.y2][x + offset.x2] == '#'
					&& tab[y + offset.y3][x + offset.x3] == '#'){
					tab_form->x = x;
					tab_form->y = y;
					tab_form->str = offset.str;
					tab_form->form = offset.form;
					return true;
				}
				
			}
		}
	}
	return false;
}

void checkAll(char tab[][4][4], int size, t_offset *tab_form)
{
	int i, j, index;
	bool valid_form;
	index = 0;
	//char list[size];
	valid_form = false;
	for ( i = 0; i < size; i++){
		for (j = 0; j < NBR_FORM; j++){
			if(checkForm(tab[i], tabforms[j], tab_form + index)){
				index++;
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