#include <unistd.h>
#include <stdio.h>

int main ()
{
	printf("avant execlp\n");
	execl("/bin/ls", "ls","-la", NULL);
	printf("apres execlp\n");

	return 0;
}