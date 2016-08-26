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
	//printf("%s\n", data->name);
		data->args = malloc (sizeof(*data->args) * (ret - i) + 1);
		data->args = strcpy(data->args, buffer + i);
	}
	return data;
}

bool applyFunction (char *buffer, int ret)
{
	t_function *data = getFunction(buffer, ret);
	if (data == NULL)
		return true;
	if (strcmp(data->name, "exit") == 0){
		freeStructFunction(&data);
		return false;
	}
	if (strcmp(data->name, "echo") == 0)
		echo(data->args);
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
			status = applyFunction (buff,ret);
		if (buff[ret-1] != '\n')
			printf("\n");
		
	}
	freeStructEnv (&struct_env);
}


