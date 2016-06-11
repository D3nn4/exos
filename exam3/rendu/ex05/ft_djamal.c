#include <stdio.h>
#include <stdbool.h>

void ft_swap(int *a, int *b)
{	
	int nb1;
	int nb2;

	nb1 = *a;
	nb2 = *b;

	*a = nb2;
	*b = nb1;
}

int ft_djamal(int i, int j, int k)
{
	while (true){
		if (k < j)
			ft_swap(&k, &j);
		if (j < i)
			ft_swap(&j, &i);
		if (i <= j && j <= k)
			return j;
	}
}

int main ()
{
	int i,j,k;
	i = 65;
	j = 39;
	k = 35;
	printf("%d\n",ft_djamal(i,j,k));

	return 0;
}