#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>



int main ()
{	
	int status_wait;
	int j = 42;
	int exit_value;
	printf("avant fork\n");
	pid_t father = fork();
	pid_t fils_pid;
	printf("apres crea fork\n");

	if (father > 0){ // pere
		/*
		while (fils_pid != wait4(fils_pid, &status_wait, WNOHANG,0)){
			printf("in wait4\n");
			sleep(1);
		}
		*/
		wait(&status_wait);
		if (WIFEXITED(status_wait)){
			printf("in wifexited\n");
			exit_value = WEXITSTATUS(status_wait);
		}
		
		printf("in father\n");
		
		printf("apres wait\n");

		printf("valeur de exit = %d\n", exit_value);
	}
	if (father == 0){ // fils
		printf("in son\n");
		sleep(5);
		exit(j);
	}
	printf("before return\n");
	return 0;
}