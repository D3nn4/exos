#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft.h"

void ft_cat(int ac, char ** av)
{

	int fd;
	int i;
	for (i = 1; i < ac; i++){
		fd = open(av[i], O_RDONLY);
		if (fd == -1){
			printf("open() of file %d failed.\n", i);			
		}
		else {
			ft_display_file(fd);
			printf("\n");
		}
		if (close(fd) == -1){
			printf("close() of file %d failed.\n", i);
		}
	}
}

int main (int argc, char **argv)
{

	if (argc < 2){
		printf("File name missing.\n");
		return 1;
	}
	ft_cat(argc, argv);
	
	
	return 0;
}