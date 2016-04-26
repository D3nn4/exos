#include <stdlib.h>

char *ft_concat_params(int argc, char **argv)
{
	if (argc > 1){
		int lenght, index, i, j;
		char *array;
		for(index = 1 ; index < argc; index++){
			i = 0;
			while (argv[index][i] != '\0'){
				lenght++;
				i++;
			}
			lenght++;
		}
		array = malloc(sizeof(*array) * (lenght + 1));
		j = 0;
		for (index = 1; index < argc; index++){
			for (i = 0; argv[index][i] != '\0'; i++){
				array[j] = argv[index][i];
				j++;
			}
			array[j] = '\n';
			j++;
		}	
		array[j] = '\0';
		return array;
	}
	return NULL;
}