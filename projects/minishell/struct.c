#include "minishell.h"

void freeStructEnv (t_env **env)
{
	int i;
	t_env *struct_env = *env;
	
	for (i = 0; struct_env->paths[i]; i++){
		free(struct_env->paths[i]);
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