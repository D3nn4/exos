#include <unistd.h>

void ft_strcapitalize(char **str)
{

	int i;
	i = 0;
	char *string;
	string = *str;
	int min_to_maj = -32;
	int maj_to_min = 32;
	while (string[i] != '\0'){
		if (string[i] >= 'a' && string[i]<= 'z'){
			if (i == 0 || (string[i-1] == ' ')
				|| (string[i-1] >= '!' && string[i-1] <= '/')
				|| (string[i-1] >= ':' && string[i-1] <= '@')){
					string[i] = string[i] + min_to_maj;
			}
		}
		if (string[i] >= 'A' && string[i] <= 'Z'){
			if((string[i-1] >= 'a' && string[i] <= 'z')
				&& (string[i-1] >= '0' && string[i] <= '9')
				&& (string[i-1] >= 'A' && string[i] <= 'Z')){
					string[i] = string[i] + maj_to_min;
			}
		}
		i++;
	}
	str = &string;
}

int main (int argc, char **argv)
{
	int i;
	if (argc == 2){
		ft_strcapitalize(&argv[1]);
		for(i = 0; argv[1][i] != '\0'; i++)
			write(1, &argv[1][i],1);
	}
	write(1, "\n",1);
	
	return 0;
}