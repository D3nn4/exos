#include "includes/ft.h"

typedef struct op_tab {
	char*			op;
	int(*f)(int, int);
} op_tab_t;

int sum(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mult(int a, int b)
{
	return a * b;
}

int divi(int a, int b)
{
	return a / b;
}

int mod(int a, int b)
{
	return a % b;
}

op_tab_t tab[] = {{"+", &sum},
				{"*", &mult},
				{"/", &divi},
				{"-", &sub},
				{"%", &mod}};

void operation(char *num1, char *c, char *num2)
{
	int i, a, b;
	a = ft_atoi(num1);
	b = ft_atoi(num2);
	for (i = 0; i < 4; i++){
		if(ft_strcmp("/", tab[i].op) == 0 && b == 0){
			ft_putstr("Stop : division by zero\n");
			return;
		}
		if(ft_strcmp("%", tab[i].op) == 0 && b == 0){
			ft_putstr("Stop : modulo by zero\n");
			return;
		}
		if (ft_strcmp(c, tab[i].op) == 0){
			ft_putnbr(tab[i].f(a, b));
			ft_putchar('\n');
			return;
		}
	}
	ft_putnbr(0);
	ft_putchar('\n');
	return;
}


int main(int argc, char **argv)
{

	if (argc == 4)
		operation(argv[1], argv[2], argv[3]);
	return 0;
}
