#include "minishell.h"

int main (int argc, char **argv, char **env)
{
	if (argc == 1)
		minishell(env);
	return 0;
}