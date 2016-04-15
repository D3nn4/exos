#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max){
		*range = NULL;
		return 0;
		}
	int *array_int;
	int lenght, index;
	lenght = max - min;
	array_int = malloc(sizeof(int) * (lenght + 1));
	if (array_int == NULL){
		*range = NULL;
		return 0;
		}
	for (index = 0; min < max; index++){
		array_int[index] = min;
		min++;
	}
	*range = array_int;
	return lenght;
}

int main()
{
	int **res, i, max, len;
	max = 5;
	len = ft_ultimate_range(res,1,max);

	ft_putnbr(len);
	ft_putchar('\n');

	for (i = 0; i < max -1; i++){
		ft_putnbr(**res + i);
		ft_putchar('\n');
	}
	return 0;
}