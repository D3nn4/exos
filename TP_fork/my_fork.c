#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main ()
{
	pid_t id = getpid();
	printf("id : %d\n", id);

	pid_t father = fork();

	if (father == 0){
		pid_t id_fils = getpid();
		printf("pid fils : %d\n", id_fils);
		printf("ppid : %d\n", getppid());
		printf("ID session fils : %d\n", getsid(id_fils));
		printf("ID process group fils : %d\n", getpgid(id_fils));
	}
	if (father > 0){
		pid_t id_pere = getpid();
		printf("pid pere : %d\n", id_pere);
		printf("ID session pere: %d\n", getsid(id_pere));
		printf("ID process group pere : %d\n", getpgid(id_pere));
	}

	pid_t last_id = getpid();
	printf("last_id : %d\n", last_id);


	return 0;
}