#include <stdio.h>
#include "ft.h"
#include "minishell.h"


void echo (char *args)
{
	if (args == NULL){
		printf("\n");
		return;
	}
	printf("%s", args);
}

/*
void cd (char *args)
{

}
*/