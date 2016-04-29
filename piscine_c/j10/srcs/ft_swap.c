void	ft_swap(int *a, int *b)
{
	int nb1;
	int nb2;

	nb1 = *a;
	nb2 = *b;

	*a = nb2;
	*b = nb1;
}