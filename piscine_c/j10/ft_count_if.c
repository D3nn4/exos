int ft_count_if(char **tab, int(*f)(char*))
{
	int i, total_of_one;
	i = 0;
	total_of_one = 0;
	while (tab[i] != 0){
		if (f(tab[i] == 1))
			total_of_one++;
		i++;
	}
	return total_of_one;
}

int main()
{

	return 0;
}