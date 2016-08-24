#ifndef __HEADER_H__
#define __HEADER_H__

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define SIZE_MAX  4096

typedef struct  s_env {
	char **raw_env;
	char **paths;
}				t_env;

void minishell(char **env);
void getPaths (char *string);
t_env *getEnv (char **env);




#endif