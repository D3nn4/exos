#include <stdlib.h>

int *ft_range(int min, int max)
{
	if (min >= max)
		return NULL;
	int *array_int;
	int lenght, n, index;
	lenght = max - min;
	array_int = malloc(sizeof(int) * (lenght + 1));
	if (array_int == NULL)
		return NULL;
	for (index = 0; min < max; index++){
		array_int[index] = min;
		min++;
	}
	return array_int;
}

int main()
{
	int *res, i, max;
	max = 5;
	res = ft_range(1,max);

	for (i = 0; i < max -1; i++){
		ft_putnbr(res[i]);
		ft_putchar('\n');
	}
	return 0;
}