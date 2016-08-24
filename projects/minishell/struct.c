#include "minishell.h"

void freeStruct (t_env **env)
{
	int i;
	t_env *struct_env = *env;
	
	for (i = 0; struct_env->paths[i]; i++){
		free(struct_env->paths[i]);
	}
	free(struct_env->paths);
	struct_env->raw_env = NULL;
	struct_env->paths = NULL;
	free(struct_env);
	struct_env = NULL;
}