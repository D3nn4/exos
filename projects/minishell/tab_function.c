#include "minishell.h"

void echo (char *args)
{
	if (args == NULL)
		return;
	printf("echo : %s", args);
}
