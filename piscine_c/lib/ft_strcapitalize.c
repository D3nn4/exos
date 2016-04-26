#include <stdlib.h>
#include "ft.h"

char *ft_strcapitalize(char *str)
{
	int i;
	i = 1;
	char all[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[i] != '\0'){
		if (ft_strstr(all, &str[i-1]) == NULL && 
			ft_strstr(letters, &str[i]) != NULL){
			str[i] = str[i] - 32;
		}
		i++;	
	}
	return str;
}