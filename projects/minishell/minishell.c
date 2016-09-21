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
		if (buffer[i] == ' ' || buffer[i] == '\t'){
			i++;
			break;
		}
		i++;
	}
	if (i > 0){
		data = malloc(sizeof(*data));
		data->name = malloc(sizeof(*data->name) * (i + 1));
		data->name = strncpy(data->name, buffer, i - 1);
		data->name[i - 1] = '\0';	
		while (buffer[i] == ' ' || buffer[i] == '\t')
			i++;
		if (buffer[i] == '\0' || buffer[i] == '\n')
			data->args = NULL;
		else {
			data->args = malloc (sizeof(*data->args) * (ret - i + 1));
			data->args = strcpy(data->args, buffer + i);
			const int end_of_args = strlen (data->args);
			if (end_of_args > 1 && data->args[end_of_args - 1] == '\n')
				data->args[end_of_args - 1] = '\0';
		}
	}
	return data;
}


bool FindBuiltInFunction (t_function *data, t_env *env)
{
	if (strcmp(data->name, "echo") == 0)
		echo(data->args);
	else if (strcmp (data->name, "cd") == 0)
		cd (data->args, env);
	else if (strcmp (data->name, "setenv") == 0)
		mySetenv (data->args, env);
	else if (strcmp (data->name, "penv") == 0)
		displayEnv (env);
	else
		return false;
	return true;
}

bool applyFunction (char *buffer, int ret, t_env *env)
{
	t_function *data = getFunction(buffer, ret);
	if (data == NULL)
		return true;
	if (strcmp(data->name, "exit") == 0
		|| strcmp(data->name, "q") == 0 
		|| strcmp(data->name, "quit") == 0){
		freeStructFunction(&data);
		return false;
	}
	if (FindBuiltInFunction(data, env) == false)
		if(findLibFunction(data, env) == false) 
			printf("%s: command not found\n", data->name);
	freeStructFunction(&data);
	return true;
}


void minishell (char **env)
{	
	size_t size_max = SIZE_MAX;
	t_env *struct_env = NULL;
		if (env != NULL && env[0] != '\0'){
			struct_env = getEnv(env);
			modifyVar(struct_env, "PWD", struct_env->current_directory);
			modifyVar(struct_env, "OLDPWD", struct_env->current_directory);
		}
		else
			struct_env = NULL;
	bool status = true;
	while (status){
		
		int ret = 0;
		//char buff[SIZE_MAX + 1];
		char *buff = NULL;
		printf("%s$>", struct_env->current_directory);
		//write(1, "$>", 2);
		ret = getline(&buff, &size_max, stdin);
		//ret = read (0, buff, SIZE_MAX);
		if (ret <= 0)
			return;
		buff[ret] = '\0';
		if (ret > 1 && buff[0] != '\n')
			status = applyFunction (buff,ret, struct_env);
		if (buff[ret-1] != '\n')
			printf("\n");
	}
	freeStructEnv (&struct_env);
}


