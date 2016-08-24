#include "minishell.h"

t_function *getFunction (char *buffer, int ret)
{
	t_function *data = malloc(sizeof(*data));
	int i = 0;
	while (buffer[i] != ' ')
		i++;
	data->name = malloc(sizeof(*data->name) * i + 1);
	data->name = strncpy(data->name, buffer, i);
	//printf("%s\n", data->name);
	data->args = malloc (sizeof(*data->args) * (ret - i) + 1);
	data->args = strcpy(data->args, buffer + i);
	return data;


}

void applyFunction (char *buffer, int ret)
{
	t_function *data = getFunction(buffer, ret);
	if (strcmp(data->name, "echo") == 0){
		echo(data->args);
	}

}


void minishell (char **env)
{	
	while (true){
		t_env *struct_env = NULL;
		if (env != NULL && env[0] != '\0')
			struct_env = getEnv(env);
		else
			struct_env = NULL;
		int ret = 0;
		char buff[SIZE_MAX + 1] = "";
		write(1, "$>", 2);
		ret = read (0, buff, SIZE_MAX);
		if (ret <= 0)
			return;
		buff[ret] = '\0';
		applyFunction (buff,ret);
		//printf("%s", buff );
		if (buff[ret-1] != '\n')
			printf("\n");
		freeStructEnv (&struct_env);
	}
}


