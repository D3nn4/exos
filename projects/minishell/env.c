#include "minishell.h"

char **getPaths (char *string)
{
	int nb_path = 1;
	int i;
	int j;
	for (i = 0; i < (int)strlen(string); i++){
		if (string[i] == ':')
			nb_path++;
	}
	char **paths = malloc(sizeof(*paths) * (nb_path + 1));
	if (paths == NULL){
		printf("error malloc getPaths\n");
		return NULL;
	}
	int curseur = 5;
	for (i = 0; i < nb_path; i++){
		j = curseur;
		while (string[j] != ':'){
			j++;
		}
		paths[i] = malloc (sizeof(**paths) * (j - curseur) + 1);
		if (paths[i] == NULL) {
			printf("error malloc path getPaths\n");
			return NULL;
		}
		paths[i] = strncpy (paths[i], string + curseur, j - curseur);
		curseur = j + 1;
	}
	paths[nb_path] = NULL;
	return paths;
}

t_env *getEnv (char **env)
{
	int i;
	t_env *struct_env = malloc(sizeof(*struct_env));
	struct_env->raw_env = env;
	for (i = 0; env[i]; i++){
		if (strncmp(env[i], "PATH=", 5) == 0){
			struct_env->paths = getPaths (env[i]);
			/*
			int j = 0;
			while (struct_env->paths[j]){
				printf("%s\n", struct_env->paths[j]);
				j++;
			}
			*/
			return struct_env;
		}
	}
	struct_env->paths = NULL;
	return struct_env;
}