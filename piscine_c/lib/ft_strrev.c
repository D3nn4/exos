void	ft_strrev(char *str)
{
	int index = 0;
	while (str[index] != '\0' )
	{
		index++;
	}
	
	while (index >= 0)
	{
		ft_putchar(str[index]);
		index--;
	}
}