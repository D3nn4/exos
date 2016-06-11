#include <unistd.h>
#include <stdbool.h>

void half_Str(int ac, char **av)
{
	int i,j;
	bool printable = true;
	for(i = 1; i < ac; i++){
		for(j = 0; av[i][j] != '\0'; j++){
			if (printable){
				write(1, &av[i][j],1);
				printable = false;
			}
			else{
				printable = true;
			}
		}
		printable = true;
		write(1, "\n", 1);
	}

}

int main (int argc, char **argv)
{
	if (argc > 1)
		half_Str(argc, argv);
	else
		write(1,"\n",1);
	return 0;

}