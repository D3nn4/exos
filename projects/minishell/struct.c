#include <stdlib.h>
#include "ft.h"
#include "minishell.h"


void freeStructEnv (t_env **env)
{
	int i;
	t_env *struct_env = *env; 
	/*
	for (i = 0; struct_env->raw_env[i]; i++){
		free(struct_env->raw_env[i]);
	}
	*/
	if (struct_env->paths != NULL){
		for (i = 0; struct_env->paths[i]; i++){
			free(struct_env->paths[i]);
		}
	}
	free(struct_env->paths);
	free(struct_env->home);
	free(struct_env->current_directory);
	struct_env->home = NULL;
	struct_env->current_directory = NULL;
	struct_env->raw_env = NULL;
	struct_env->paths = NULL;
	free(struct_env);
	struct_env = NULL;
}

void freeStructFunction (t_function **function)
{
	t_function *to_remove = *function;
	free(to_remove->name);
	free(to_remove->args);
	to_remove->name = NULL;
	to_remove->args = NULL;
	free(to_remove);
	to_remove = NULL;
}