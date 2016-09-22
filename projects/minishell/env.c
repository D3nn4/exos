#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft.h"
#include "minishell.h"

void displayEnv (t_env *env)
{
	int i;
	if (env == NULL || env->raw_env == NULL){
		printf("error : no env\n");
		return;
	}
	for(i = 0; env->raw_env[i] != NULL; i++) {
		printf("%s\n", env->raw_env[i]);
	}
}

char **getPaths (char *string)
{
	int nb_path = 1;
	int i, j;
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

void getHome (char *string, t_env *env)
{
	int i;
	int lenght = 0;
	for (i = 5; string[i] ; i++)
		lenght++;
	env->home = malloc(sizeof(*env->home) * lenght + 1);
	env->current_directory = malloc(sizeof(*env->current_directory) * lenght + 1);
	env->home = strcpy(env->home, string + 5);
	env->current_directory = strcpy (env->current_directory, string + 5);
}

t_env *getEnv (char **env)
{
	int i;
	t_env *struct_env = malloc(sizeof(*struct_env));
	if (env == NULL ){
		addNewVar (struct_env, "PWD", "/");
		addNewVar (struct_env, "OLDPWD", "/");
		addNewVar (struct_env, "HOME", "/");
		addNewVar (struct_env, "PATH", "/");
	}
	struct_env->raw_env = env;
	struct_env->paths = NULL;
	struct_env->current_directory = NULL;
	struct_env->home = NULL;
	for (i = 0; env[i]; i++){
		if (strncmp(env[i], "PATH=", 5) == 0)
			struct_env->paths = getPaths (env[i]);
		if (strncmp (env[i], "HOME=", 5) == 0)
			getHome(env[i], struct_env);
	}
	
	return struct_env;
}