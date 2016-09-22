#include <stdio.h>
#include <dirent.h>
#include "ft.h"
#include "minishell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


char *addSeparator (char *string)
{
	int size = strlen (string);
	if ((string[size - 1] != '/')){
		string = realloc (string, sizeof(*string) * (size + 2));
		strcat(string, "/");
	}
	return string;
}

char *previousDir (char *str)
{
	char *new_str = NULL;
	int size, i,j;
	size = strlen(str) - 1; //to be on last /
	i = size;
	while (str[i - 1] != '/')
		i--;
	new_str = malloc (sizeof(*new_str) * (i + 1)); // +1 = Null byte
	if (new_str == NULL)
		return NULL;
	for (j = 0; j < i+1; (new_str[j++] = '\0'));
	//new_str[0] = '\0';
	new_str = strncpy(new_str, str, i);
	//printf("str : %s\n", str);
	//printf("new_str : %s\n", new_str);
	free (str);
	return new_str;
}

char *eraseDots (char *str)
{
	if (strlen(str) == 1 && str[0] == '.')
		return str;
	int i;
	char *new_str = NULL;
	new_str = malloc (sizeof(*new_str) * (strlen(str) + 1));
	if (new_str == NULL)
		return NULL;
	new_str[0] = '\0';
	for (i = 0; str[i] != '\0'; i++){
		while (str[i] == '.'){
			if (str[i + 1] == '.'){
				new_str = previousDir(new_str);
				if (strlen(new_str) == 1)
					return new_str;
				i = i + 2; //from ../ next dir
			}
			else if (str[i + 1] == '/' || str[i + 1] == '\0')
				i = i + 2; //from ./ next dir
			else 
				printf("error eraseDots\n");
		}
		strncat (new_str, str + i, 1);
	}
	strncat (new_str, str + i, 1);
	free (str);
	return new_str;
}

char *isDir (char *args, t_env *env)
{	
	if ((strcmp(args, "..") == 0) && strcmp(env->current_directory, "/") == 0 ) 
		return env->current_directory;
	char *next_dir = malloc(sizeof(*next_dir) * (strlen(env->current_directory) + 1)); // +1: Null byte
	next_dir = strcpy(next_dir, env->current_directory);
	DIR *dir = NULL;
	next_dir = addSeparator(next_dir);
	next_dir[strlen(next_dir)] = '\0';
	if (args[0] == '/')
		args = args + 1;
	int temp_size = strlen(next_dir) + strlen(args);
	char * temp_dir = realloc (next_dir, sizeof(*next_dir) * (temp_size + 1)); // +1: Null byte
	next_dir = temp_dir;
	next_dir[temp_size] = '\0';
	if (next_dir == NULL){
		printf("error realloc isDir\n");
		return NULL;
	}
	strcat (next_dir, args);
	next_dir = eraseDots (next_dir);
	if (strcmp(next_dir, "/") != 0) {
		dir = opendir (next_dir);
		if (dir == NULL){
			closedir (dir);
			return NULL;
		}
		closedir(dir);
	}
	return next_dir;
}

void cd (char *args, t_env *env)
{
	
	char *new_dir = NULL;
	if (args == NULL){
		modifyVar(env, "OLDPWD", env->current_directory);
		modifyVar(env, "PWD", env->home);
		chdir(env->home);
		env->current_directory = env->home;
		return;
	}
	else if (strcmp(args, ".") == 0)
		return;
	
	new_dir = isDir(args, env);
	if (new_dir != NULL){
		modifyVar(env, "OLDPWD", env->current_directory);
		modifyVar(env, "PWD", new_dir);
		chdir(new_dir);
		free(env->current_directory);
		env->current_directory = new_dir;
	}
	else
		printf("minishell: cd: %s: No such file or directory\n", args);


}
