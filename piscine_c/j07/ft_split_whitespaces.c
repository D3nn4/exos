#include <stdlib.h>

char **ft_split_whitespaces(char *str)
{
	char **array_ptr;
	int index, i, lenght, LEN;
	index = 0;
	LEN = 0;
	lenght = ft_count_words(str);
	array_ptr = malloc(sizeof(*array_ptr) * (lenght + 1));
	if (array_ptr == NULL)
		return NULL;
	for (i = 0; str[i] != '\0'; i++){
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'){
			LEN++;
		}
		else{
			array_ptr[index] = malloc(sizeof(**array_ptr) * (LEN + 1));
			ft_strncpy(array_ptr[index], str + (i - LEN), LEN);
			index++;
			LEN = 0;
		}
	}
	array_ptr[index] = malloc(sizeof(**array_ptr) * (LEN + 1));
	if (array_ptr[index] == NULL)
		return NULL;
	ft_strncpy(array_ptr[index], str + (i - LEN), LEN);
	array_ptr[index + 1] = 0;
	return array_ptr;
}




int main()
{
	int i;
	i = 0;
	char ** array;
	char string[] = "Hello World";
	array = ft_split_whitespaces(string);

	for (i = 0; array[i] != 0; i++){
		ft_putstr(array[i]);
		free(array[i]);
		ft_putchar('\n');
	}
	free(array);


	return 0;
}