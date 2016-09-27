#include <stdio.h>

int main ()
{
	printf("pid : %d\n", getpid());

	while (42)
		printf("toto\n");
	return 0;
}