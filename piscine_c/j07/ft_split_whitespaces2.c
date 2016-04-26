#include <stdlib.h>

char **fill_array(char *str, char **array_ptr)
{
	int i, tmp, LEN, index;
	index = 0;
	for (i = 0; str[i] != '\0'; i++){
		if (ft_is_alpha(str[i])){
			tmp = i;
			while (ft_is_alpha(str[i]))
				i++;
			LEN = i - tmp;
			array_ptr[index] = malloc(sizeof(**array_ptr) * (LEN + 1));
			if (array_ptr[index] == NULL)
				return NULL;
			ft_strncpy(array_ptr[index], str + tmp, LEN);;
			index++;
		}
	}
	array_ptr[index] = 0;
	return array_ptr;
}

char **ft_split_whitespaces(char *str)
{
	if (str[0] == '\0')
		return NULL;
	char **array_ptr;
	int lenght;
	lenght = ft_count_words(str);
	array_ptr = malloc(sizeof(*array_ptr) * (lenght + 1));
	if (array_ptr == NULL)
		return NULL;
	array_ptr = fill_array(str, array_ptr);
	return array_ptr;
}



int main()
{
	int i;
	char ** array;
	char string[] = "Hello World";

	array = ft_split_whitespaces(string);
	ft_print_words_tables(array);

	for (i = 0; array[i] != 0; i++){
		free(array[i]);
	}
	free(array);

	return 0;
}