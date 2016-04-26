#include <stdbool.h>

int ft_count_words(char *str)
{
	int lenght, i;
	lenght = 0;
	for (i = 0; str[i] != '\0'; i++){
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){ 
			if (str[i + 1] != ' ' || str[i + 1] != '\t' 
				|| str[i + 1] != '\n' || str[i + 1] != '\0'){ 
			lenght++;
			}
		}
	}
	lenght++;
	return lenght;
}