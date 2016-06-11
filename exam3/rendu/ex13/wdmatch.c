#include <unistd.h>

void ft_putstr(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++){
		write(1, &str[i], 1);
	}
}

void wdmatch(char *str1, char *str2)
{
	int i,j;
	j = 0;
	for (i = 0; str1[i] != '\0'; i++){
		if (str2[j] == '\0')
			return;
		while (str1[i] != str2[j]){
			j++;
		}
		j++;
	}
	if (str1[i-1] == str2[j-1]){
		ft_putstr(str1);
	}
	

}


int main (int argc, char **argv)
{
	if (argc == 3){
		wdmatch(argv[1], argv[2]);
	}
	write(1, "\n", 1);

	return 0;
}