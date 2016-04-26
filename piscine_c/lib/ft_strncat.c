char *ft_strncat(char *dest, char *src, int nb)
{
	int i, j;
	i = 0;
	j = 0;
	while (dest[i] != '\0'){
		i++;
	}
	for (j; src[j] != '\0' && j < nb; j++){
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return dest;
}