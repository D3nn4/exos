#include "ft.h"
#include "minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>




void printPath (t_env *env)
{
	int i;
	for (i = 0; env->paths[i] != NULL; i++) {
		printf("%s\n", env->paths[i]);
	}
}



char *addPath (char *name, char *path)
{
	char *str = malloc(sizeof(*str) * (strlen(name) + strlen(path) + 2)); // +2 => separator + \0
	str = strcpy(str,path);
	strcat(str, "/");
	strcat(str, name);
	strcat(str, "\0");
	return str;

}

bool testLibFunction (t_function *data, t_env *env)
{
	
	int i;
	char *path_to_test = NULL;
	for (i = 0; env->paths[i] != NULL; i++) {
		path_to_test = addPath (data->name, env->paths[i]);

		pid_t father;
		int return_value = 0;
		int status_wait;
		father = fork();
		if (father > 0){
			wait(&status_wait);
			if (WIFEXITED(status_wait))
				return_value = WEXITSTATUS(status_wait);
		}
		if (father == 0){
			//printf("trying a path\n");
			return_value = execve (path_to_test, data->args, env->raw_env);
			exit(return_value);
		}
		free(path_to_test);
		if (return_value == 0)
			return true;
	}
	return false;	
}

bool findLibFunction (t_function *data, t_env *env)
{
	return testLibFunction(data, env);
	
}