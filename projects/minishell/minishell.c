#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ft.h"
#include "minishell.h"

t_function *getFunction (char *buffer, int ret)
{
	t_function *data = NULL;
	int i = 0;
	while (buffer[i] != '\0'){
		if (buffer[i] == ' '){
			i++;
			break;
		}
		i++;
	}
	if (i > 0){
		data = malloc(sizeof(*data));
		data->name = malloc(sizeof(*data->name) * i + 1);
		data->name = strncpy(data->name, buffer, i - 1);
		data->name[i-1] = '\0';
		data->args = malloc (sizeof(*data->args) * (ret - i) + 1);
		data->args = strcpy(data->args, buffer + i);
	}
	const int end_of_args = strlen (data->args);
	if (end_of_args > 1 && data->args[end_of_args - 1] == '\n')
		data->args[end_of_args - 1] = '\0';

	
	return data;
}

bool applyFunction (char *buffer, int ret, t_env *env)
{
	t_function *data = getFunction(buffer, ret);
	//printf("%p\n", data);
	if (data == NULL)
		return true;
	else if (strcmp(data->name, "exit") == 0){
		freeStructFunction(&data);
		return false;
	}
	else if (strcmp(data->name, "echo") == 0)
		echo(data->args);
	else if (strcmp (data->name, "cd") == 0)
		cd (data->args, env);
	else 
		printf("%s: command not found\n", data->name);
	freeStructFunction(&data);
	return true;
}


void minishell (char **env)
{	
	t_env *struct_env = NULL;
		if (env != NULL && env[0] != '\0')
			struct_env = getEnv(env);
		else
			struct_env = NULL;
	bool status = true;
	while (status){
		
		int ret = 0;
		char buff[SIZE_MAX + 1];
		write(1, "$>", 2);
		ret = read (0, buff, SIZE_MAX);
		if (ret <= 0)
			return;
		buff[ret] = '\0';
		if (ret > 1 && buff[0] != '\n')
			status = applyFunction (buff,ret, struct_env);
		if (buff[ret-1] != '\n')
			printf("\n");
		printf("dir : %s\n", struct_env->current_directory);
	}
	freeStructEnv (&struct_env);
}


