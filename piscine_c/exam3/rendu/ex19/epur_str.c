#include <unistd.h>

void epur_str(char *str)
{	
	int i;
	for(i = 0; str[i] != '\0'; i++){
		
		
	}


}

int main (int argc, char **argv)
{
	if (argc == 2){
		epur_str(argv[1]);
	}
	write(1, "\n",1);
	return 0;
}