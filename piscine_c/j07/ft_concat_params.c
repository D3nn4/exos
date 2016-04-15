#include <stdlib.h>

char *ft_concat_params(int argc, char **argv)
{
	if (argc > 1){
		int lenght, index,i, LEN;
		char *array;
		i = 0;
		for(index = 1 ; index < argc; index++){
			while (argv[index][i] != '\0'){
				lenght++;
				i++;
			}
			i = 0;
			lenght++;
		}
		array = malloc(sizeof(array) * (lenght + 1));
		LEN = sizeof(array) * (lenght + 1);
		for (LEN; LEN > 0; LEN--){
			for(index = 1 ; index < argc; index++){
				while (argv[index][i] != '\0'){
					array[LEN] = argv[index][i];
					LEN++;
					i++;
				}
			i = 0;
			LEN++;
			array[LEN] = '\n';
			LEN++;
			}
		}
		*argv = array;
		return *argv;
	}
}

int main (int argc, char **argv)
{
	ft_concat_params(argc,argv);
	ft_putstr(*argv);
	ft_putchar('\n');
	return 0;
}