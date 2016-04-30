int *ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *res_tab;
	res_tab = malloc (sizeof(*res_tab) * length);
	for (i = 0; i < length; i++){
		res_tab[i] = f(tab[i]);
	}
	return res_tab;
}

int main()
{

	return 0;
}