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

bool applyLibFunction (char *path_to_test, t_function *data, t_env *env)
{
	int return_value = 0;
	int status_wait;
	pid_t father;
	father = fork();
	if (father > 0){
		wait(&status_wait);
		if (WIFEXITED(status_wait))
			return_value = WEXITSTATUS(status_wait);
	}
	if (father == 0){
		//printf("%s\n", path_to_test);
		if (data->args == NULL){
			char *argv[2] = {"ls", NULL};
			return_value = execve (path_to_test, argv, env->raw_env);
		}
		else{
			char *argv[3] = {"ls", data->args, NULL};
			return_value = execve (path_to_test, argv, env->raw_env);
		}
		exit(return_value);
	}
	if (return_value == 0)
		return true;
	return false;
}

bool testLibFunction (t_function *data, t_env *env)
{
	int i;
	char *path_to_test = NULL;
	//printPath(env);
	for (i = 0; env->paths[i] != NULL; i++) {
		path_to_test = addPath (data->name, env->paths[i]);
		struct stat *buf = NULL;
		buf = malloc(sizeof(buf));
		if(stat(path_to_test, buf) == 0) {
			return applyLibFunction(path_to_test, data, env);
		}
		free(path_to_test);
		free(buf);
	}
	return false;	
}

bool findLibFunction (t_function *data, t_env *env)
{
	return testLibFunction(data, env);
	
}