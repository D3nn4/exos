#include <stdlib.h>

char **fill_array(char *str,char *charset, char ** array_ptr)
{
	char *temp;
	int char_lenght, word_lenght, index;
	char_lenght = charset_lenght(charset);
	index = 0;
	while (ft_strstr(str, charset) != NULL ){
		temp = ft_strstr(str, charset);
		if (str != temp){
			word_lenght = temp - str;
			array_ptr[index] = malloc(sizeof(**array_ptr) * (word_lenght + 1));
			if (array_ptr[index] == NULL)
				return NULL;
			ft_strncpy(array_ptr[index], str, word_lenght);
			index++;
		}
		str = temp + char_lenght;
	}
	if (str[0] != '\0'){
		word_lenght = ft_strlen(str);
		array_ptr[index] = malloc(sizeof(**array_ptr) * (word_lenght + 1));
		if (array_ptr[index] == NULL)
				return NULL;
		ft_strcpy(array_ptr[index], str);
	}
	array_ptr[index + 1] = 0;
	return array_ptr;
}

int charset_lenght (char *charset)
{
	int i, charset_lenght;
	charset_lenght = 0;
	for (i = 0; charset[i] != '\0'; i++){
		charset_lenght++;
	}
	return charset_lenght;
}

int lenght_array_ptr (char *str, char *charset)
{
	char *found;
	int lenght_array_ptr, lenght;
	lenght_array_ptr = 0;
	lenght = charset_lenght(charset);
	while (ft_strstr(str, charset) != NULL)	{
		found = ft_strstr(str, charset);
		if (str != found) {
			lenght_array_ptr++;
			str = found + lenght;
		}
		else {
			str = found + lenght;
		}
	}
	if (str[0] != '\0'){
		lenght_array_ptr++;
	}
	return lenght_array_ptr;
}

char **ft_split(char *toto, char *charset)
{
	int lenght;
	char **array_ptr;
	if (toto[0] == '\0')
		return NULL;
	lenght = lenght_array_ptr(toto, charset);
	array_ptr = malloc(sizeof(*array_ptr) * (lenght + 1));
	if (array_ptr == NULL)
		return NULL;
	fill_array(toto, charset, array_ptr);
	return array_ptr;
}

int main()
{
	int i, lenght;
	char str[] = "coucoutotolestotoamis";
	char charset[] = "toto";
	char **array;

	lenght = lenght_array_ptr(str,charset);
	array = ft_split(str, charset);
	

	for (i = 0; i != lenght; i++) {
		ft_putstr(array[i]);
		free(array[i]);
		ft_putchar('\n');
	}
	free(array);

	return 0;
}