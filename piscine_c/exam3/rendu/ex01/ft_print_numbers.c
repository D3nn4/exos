 #include <unistd.h>


void ft_print_numbers(void)
{
	int i;
	char letter;
	for (i = 0; i <= 9; i++){
		letter = i + '0';
		write(1, &letter,1);
	}
	write(1, "\n", 1);
}

int main ()
{
	ft_print_numbers();
	return 0;
}