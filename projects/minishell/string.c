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

char *eraseDots (char *str)
{
	if (strlen(str) == 1 && str[0] == '.')
		return str;
	int i;
	char *new_str = malloc (sizeof(*new_str) * (strlen(str) + 1));
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