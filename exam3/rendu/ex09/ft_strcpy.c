#include <stdio.h>

char *ft_strcpy(char *dest, char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++){
		dest[i] = str[i];
	}
	dest[i] = '\0';
	return dest;
}

/*
int ft_strlen (char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return i;
}

int main()
{
	char *str;
	str = "Coucou les amis.";
	char dest[ft_strlen(str)];
	ft_strcpy(dest, str);
	printf("%s\n", dest);

	return 0;
}
*/