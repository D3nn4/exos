#include "minishell.h"

void minishell (char **env)
{	
	t_env *struct_env;
	if (env != NULL && env[0] != '\0')
		struct_env = getEnv(env);
	else
		struct_env = NULL;
	int ret = 0;
	char buff[SIZE_MAX + 1] = "";
	write(1, "$>", 2);
	ret = read (0, buff, SIZE_MAX);
	buff[ret] = '\0';
	printf("%s\n", buff );

}


