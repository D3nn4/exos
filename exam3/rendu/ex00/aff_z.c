#include <unistd.h>

void aff_z(char *str)
{	
	int i;
	for (i = 0; str[i] != '\0'; i++){
		if (str[i] == 'z'){
			write(1 , &str[i], 1);
			write(1, "\n", 1);
			return;
		}	
	}
	write(1, "z\n", 2);
}

int main ()
{
	char *str;
	str = "hello";
	aff_z(str);

	return 0;
}