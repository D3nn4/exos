#include <unistd.h>
#include "../ft_putchar.c"
#include "../ft_putstr.c"

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
			if (str[index] == to_find[j]){
				return (&str[i]);
			}
			else
				index = 0;
		}	
	}
}

int main ()
{
	char string[] = "Coucou les amis";
	char to_find[] = "les";
	
	ft_putstr(ft_strstr(string, to_find));
	


	return (0);
}