#include <stdlib.h>
#include "ft.h"


int ft_str_is_numeric(char *str)
{
	int i;
	i = 0;
	char numbers[] = "0123456789";
	while (str[i] != '\0'){
		if (ft_strstr(numbers, &str[i]) != NULL)
			i++;
		else 
			return 0;	
	}
	return 1;
}