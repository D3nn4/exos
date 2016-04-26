int	ft_atoi(char *str)
{
	int	nb;
	int index = 0;
	int res = 0;
		
	while (str[index] != '\0' )
	{
		res = res*10;
		nb = str[index] - '0';
		res = (res + nb);
		index++;
	}	
	return (res);			
}