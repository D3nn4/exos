#include <stdio.h>

int strLen(char *str)
{
	int i, size;
	size = 0;
	for (i = 0; str[i] != '\0'; i++){
		size++;
	}

	return size;
}

char *ft_strrev(char *str)
{
	int lenght, i, j;
	lenght = strLen(str);
	char string[lenght];
	j = lenght - 1;
	for(i = 0; i < lenght; i++){
		string[i] = str[j];
		j--;
	}
	string[i] = '\0';
	str = string;
	return str;
}

int main()
{
	char *str;
	str = "abcde";
	printf("%s\n", str);
	ft_strrev(str);
	printf("%s\n", str);

	return 0;
}

