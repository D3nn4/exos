#include "includes/ft.h"

void ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;
	for (i = 0; i < length; i++){
		f(tab[i]);
		ft_putchar('\n');
	}

}

int *fill_tab(int length)
{
	int *tab;
	int i;
	tab = malloc(sizeof(*tab) * length);
	for (i = 0; i < length; i++){
		tab[i] = i;
	}
	return tab;

}

int main ()
{
	void (*f)(int);
	int *tab = fill_tab(1337);
	f = &ft_putnbr;
	ft_foreach(tab, 1337, f);

	return 0;
}