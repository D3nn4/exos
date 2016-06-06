#ifndef __HEADER_H__
#define __HEADER_H__
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct letters 
{
	char corner_up_right;
	char corner_up_left;
	char corner_down_right;
	char corner_down_left;
	char border_hor;
	char border_ver;
	char inside;
	char *str;
} 			t_letters;

int widht (char *buf);
int height (char *buf);
char **getTabFromBuffer(char *buf, int widht, int height);
bool check_colle(char **tab2D, int widht, int height, t_letters colle);


#endif