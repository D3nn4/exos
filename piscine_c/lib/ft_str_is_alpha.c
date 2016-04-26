#include <stdlib.h>
#include "ft.h"

int ft_str_is_alpha(char *str)
{
	int i;
	i = 0;
	char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (str[i] != '\0'){
		if (ft_strstr(letters, &str[i]) != NULL)
			i++;
		else 
			return 0;	
	}
	return 1;
}