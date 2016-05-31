#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft.h"

#define BUF_SIZE 1024

void ft_tail (int fd)
{
	int o_total;
	char buf[BUF_SIZE + 1];
	o_total = read(fd, buf, BUF_SIZE);
	buf[o_total] = '\0';
	ft_putstr(&buf[o_total - 5]);
	
}

int main (int argc, char **argv)
{
	if (argc < 2){
		printf("File name missing.\n");
		return 1;
	}
	if (argc > 2){
		printf("Too many arguments.\n");
		return 1;
	}

	int fd;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1){
		printf("open() failed.\n");
		return 1;
	}
	else {
		ft_tail(fd);
	}
	if (close(fd) == -1){
		printf("close() failed.\n");
		return 1;
	}

	return 0;
}