#include "ft.h"
#include "minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



void printPath (t_env *env)
{
	int i;
	for (i = 0; env->paths[i] != NULL; i++) {
		printf("%s\n", env->paths[i]);
	}
}

bool findLibFunction (t_function *data, t_env *env)
{
	printPath(env);
	return false;
}