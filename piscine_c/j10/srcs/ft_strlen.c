int	ft_strlen(char *str)
{
	int index = 0;
	while (str[index] != '\0' )
	{
		index++;
	}
	return index;
}