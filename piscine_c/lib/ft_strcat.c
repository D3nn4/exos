char *ft_strcat(char *dest, char *src)
{
	int i, j;
	i = 0;
	j = 0;
	while (dest[i] != '\0'){
		i++;
	}
	for (j; src[j] != '\0'; j++){
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return dest;
}