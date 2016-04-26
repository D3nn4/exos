#include <stdlib.h>
#include "ft.h"

char *ft_strstr(char *str, char *to_find)
{
	int i, j, index;
	index = 0;
	for (i = 0; str[i] != '\0'; i++){
		if (str[i] == to_find[0]){
			index = i;
			for (j = 0; str[index] == to_find[j] && to_find[j] != '\0'; j++){
				if (str[index] == to_find[j]){
					index++;
				}
			}
			if (str[index - 1] == to_find[j - 1]){
				return (str + i);
			}
			else
				index = 0;
		}	
	}
	return NULL;
}