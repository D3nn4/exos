#include <unistd.h>

void rotone (char *av)
{
	int i;
	for(i = 0; av[i] != '\0'; i++){
		if (av[i] >= 'a' && av[i] <= 'z'){
			if (av[i] == 'z')
				write(1, "a", 1);
			else{
				char c = av[i] + 1;
				write(1, &c, 1);
			}
		}
		else if (av[i] >= 'A' && av[i] <= 'Z'){
			if (av[i] == 'Z')
				write(1, "A", 1);
			else{
				char c = av[i] + 1;
				write(1, &c, 1);
			}
		}
		else
			write(1, &av[i], 1);
	}
}

int main (int argc, char **argv)
{
	if (argc == 2){
		rotone(argv[1]);
	}
	write(1, "\n", 1);

	return 0; 
}