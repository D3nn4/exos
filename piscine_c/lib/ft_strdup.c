#include <stdlib.h>

char *ft_strdup(char *src)
{
	char *str_dup;
	int lenght, index;
	lenght = 0;
	index = 0;
	while (src[lenght] != '\0'){
		lenght++;
	}
	// init chaine de caractere oú dupliquer
	str_dup = malloc(sizeof(*src) * (lenght + 1));
	// si memoire insufisante renvoyer NuLL
	if (str_dup == NULL){
		return NULL;
	}
	// dupliquér src
	for (index; index < lenght; index++){
		str_dup[index] = src[index];
	}
	str_dup[index] = '\0';
	// renvoyer src
	return str_dup;
}