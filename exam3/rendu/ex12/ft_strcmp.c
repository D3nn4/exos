#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	int i;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++){
		if (s1[i] < s2[i])
			return -1;
		if (s1[i] > s2[i])
			return 1;
	}
	return 0;
}

/*
int main ()
{
	char *str1;
	str1 = "Hello";
	char *str2;
	str2 = "coucou";
	ft_strcmp(str2, str1);
	return 0;
}
*/