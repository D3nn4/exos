int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;
	for (i = 0; i < length - 1; i++){
		if (f(tab[i], tab[i + 1] > 0))
			return 0;
	}
	return 1;
}

int main()
{

	return 0;
}