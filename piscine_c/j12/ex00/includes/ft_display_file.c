#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft.h"

#define BUF_SIZE 4



void ft_display_file (int fd)
{
	int ret;
	char buf[BUF_SIZE + 1];
	while (ret = read(fd, buf, BUF_SIZE)){
		buf[ret] = '\0';
		printf("%s", buf);
	}
}

/*
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
		ft_display_file(fd);
	}
	if (close(fd) == -1){
		printf("close() failed.\n");
		return 1;
	}

	return 0;
}
*/