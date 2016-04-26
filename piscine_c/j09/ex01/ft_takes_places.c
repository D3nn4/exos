#include "../../lib/ft.h"
#include <stdio.h>


void	ft_takes_place(int hour)
{
	int h;
	if (hour > 12)
		h = hour - 12;
	else
		h = hour;
	ft_putstr("THE FOLLOWING TAKES PLACE BETWEEN ");
	if (hour == 11)
		printf("%d.00 A.M. AND %d.00 P.M.\n", h, (h+1));
	if (hour == 23)
		printf("%d.00 P.M. AND %d.00 A.M.\n", h, (h+1));
	if (hour < 11)
		printf("%d.00 A.M. AND %d.00 A.M.\n", h, (h+1));
	if (12 <= hour && hour < 23)
		printf("%d.00 P.M. AND %d.00 P.M.\n", h, (h+1));
}

int main ()
{
	ft_takes_place(12);
	return 0;
}