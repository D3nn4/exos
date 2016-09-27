#include <stdio.h>


void ft_swap(int *a, int *b)
{	
	int nb1;
	int nb2;

	nb1 = *a;
	nb2 = *b;

	*a = nb2;
	*b = nb1;
}

int main()
{
	int a;
	int b;
	a = 3;
	b = 5;
	printf("%d\n%d\n",a,b);
	ft_swap(&a, &b);
	printf("%d\n%d\n",a,b);

	return 0;
}