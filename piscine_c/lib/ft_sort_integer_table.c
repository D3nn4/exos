void	ft_sort_integer_table(int *tab, int size)
{
	int index = 0;
	if (size < 2)
	{
		return;
	}
	
	while (index < size - 1)
	{
		if (tab[index] < tab[index + 1])
		{
			index++;			
		}
		else
		{
			int a = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = a;
			index = 0;
		}	
	}
}