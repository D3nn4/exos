#ifndef __HEADER_H__
#define __HEADER_H__

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



#define SIZE_MAX  4096

typedef struct  s_env {
	char **raw_env;
	char **paths;
	char *home;
	char *current_directory;
}				t_env;

typedef struct 	s_function {
	char *name;
	char *args;

}				t_function;

void minishell(char **env);
void freeStructEnv (t_env **struct_env);
bool applyFunction (char *buffer, int ret);
void getHome (char *string, t_env *env);
void echo (char *args);
t_function *getFunction (char *buffer, int ret);
char **getPaths (char *string);
t_env *getEnv (char **env);




#endif