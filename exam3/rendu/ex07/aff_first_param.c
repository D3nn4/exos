#include <unistd.h>

void aff_first_param(char *av)
{
	int i;
	for (i = 0; av[i] != '\0'; i++){
		write(1, &av[i], 1);
	}
}

int main (int argc, char **argv)
{
	if (argc > 1){
		aff_first_param(argv[1]);
	}
	write(1, "\n", 1);

	return 0;
}