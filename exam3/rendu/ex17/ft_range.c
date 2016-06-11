#include <stdlib.h>
//#include <stdio.h>

int *ft_range(int min, int max)
{
	if (min => max)
		return 0;
	int *intTab;
	int i;
	intTab = malloc(sizeof(int *) * (max-min));
	if (intTab){
		for (i = 0; min < max; i++){
			intTab[i] = min;
			min++;
		}
	}
	return intTab;
}

/*
int main ()
{
	int *tab;
	int min, max;
	min = 3;
	max = 9;
	tab = ft_range(min,max);

	int i;
	for (i = 0; i < (max - min); i++){
		printf("%d", tab[i]);

	}

	return 0;

}
*/