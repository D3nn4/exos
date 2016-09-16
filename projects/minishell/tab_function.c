#include <stdio.h>
#include <dirent.h>
#include "ft.h"
#include "minishell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>




void echo (char *args)
{
	if (args == NULL){
		printf("\n");
		return;
	}
	printf("%s\n", args);
}

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
	int size, i;
	size = strlen(str) - 1; //to be on last /
	i = size;
	while (str[i - 1] != '/')
		i--;
	new_str = malloc (sizeof(*new_str) * (i + 1)); // +1 = Null byte
	new_str = strncpy(new_str, str, i);
	printf("str : %s\n", str);
	printf("new_str : %s\n", new_str);
	free (str);
	return new_str;
}

char *eraseDots (char *str)
{
	int i;
	char *new_str = malloc (sizeof(*new_str) * (strlen(str) + 1));
	for (i = 0; str[i] != '\0'; i++){
		while (str[i] == '.'){
			if (str[i + 1] == '.'){
				// go previous dir !! TO DO !!
				new_str =  previousDir(new_str);
				printf("new_str eraseDots: %s\n", new_str);
				i = i + 2; //from ../ next dir
			}
			else if (str[i + 1] == '/')
				i =i + 2; //from ./ next dir
			else 
				printf("toto\n");
		}
	strncat (new_str, str + i, 1);
	}
	strncat (new_str, str + i, 1);
	printf("hello erase dots\n");
	free (str);
	return new_str;
}

char *isDir (char *args, t_env *env)
{	
	//printf("args: %s\n", args);
	char *next_dir = malloc (sizeof(*next_dir) * strlen (env->current_directory) + 1); // +1: Null byte
	next_dir = strcpy (next_dir, env->current_directory);
	DIR *dir = NULL;
	//printf("next_dir: copy: %s\n", next_dir);
	next_dir = addSeparator(next_dir);
	if (args[0] == '/')
		args = args + 1;
	//printf("next_dir: addSeparator: %s\n", next_dir);
	int temp_size = strlen(next_dir) + strlen(args);
	next_dir = realloc (next_dir, sizeof(*next_dir) * (temp_size + 1)); // +1: Null byte
	//printf("next_dir: realloc: %s\n", next_dir);
	if (next_dir == NULL){
		printf("error realloc isDir\n");
		return NULL;
	}
	strcat (next_dir, args);
	printf("next_dir: strcat: %s\n", next_dir);
	next_dir = eraseDots (next_dir);
	dir = opendir (next_dir);
	if (dir == NULL){
		closedir (dir);
		return NULL;
	}
	closedir(dir);
	return next_dir;
}



void cd (char *args, t_env *env)
{
	char *new_dir = NULL;
	if (args[0]== '\0'){
		env->current_directory = env->home;
		return;
	}
	
	new_dir = isDir(args, env);
	if (new_dir != NULL){
		free(env->current_directory);
		env->current_directory = new_dir;
	}
	else
		printf("minishell: cd: %s: No such file or directory\n", args);


}
