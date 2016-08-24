#include "minishell.h"

void getPaths (char *string)
{
	int nb_path = 1;
	int i;
	for (i = 0; i < (int)strlen(string); i++){
		if (string[i] == ':')
			nb_path++;
	}
	printf("%d\n", nb_path);


}

t_env *getEnv (char **env)
{
	int i;
	t_env *struct_env = malloc(sizeof(*struct_env));
	struct_env->raw_env = env;
	for (i = 0; env[i]; i++){
		if (strncmp(env[i], "PATH=", 5) == 0){
			struct_env->paths = getPaths (env[i]);
			return struct_env;
		}
	}
	struct_env->paths = NULL;
	return struct_env;
}