#include "ft.h"
#include "minishell.h"
#include <string.h>
#include <stdlib.h>

void *simple_error (char *function, char *where)
{
	printf("error %s %s\n",function,where);
	return NULL;
}