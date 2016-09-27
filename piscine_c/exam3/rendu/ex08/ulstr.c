#include <unistd.h>

void ulstr (char *str)
{
	int i;
	int maj_to_min = 32;
	int min_to_maj = -32;
	for (i = 0; str[i] != '\0'; i++){
		if (str[i] <= 'Z' && str[i] >= 'A'){
			char letter = str[i] + maj_to_min;
			write(1, &letter, 1);
		}
		else if (str[i] <= 'z' && str[i] >= 'a'){
			char letter = str[i] + min_to_maj;
			write(1, &letter, 1);
		}
		else
			write(1, &str[i], 1);
	}
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		ulstr(argv[1]);
	}
	write(1, "\n", 1);

	return 0;
}