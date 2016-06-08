#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
//#include "header.h"

#define BUF_SIZE 4096


int pieces_nbr (int fd)
{
	int ret, size;
	char buf[BUF_SIZE + 1]; 
	while (ret = read(fd, buf, BUF_SIZE)){
		buf[ret] = '\0';
		int i;
		for (i = 0; buf[i] != '\0'; i++){
			if (buf[i] == '\n' && buf[i - 1] == '\n')
				size++;
		}
	}
	if (close(fd) == -1)
		printf("fillit : close() failed.\n");
	return size + 1;
}

void getTetriTab (int fd, int size, char ***tab)
{
	int i, j, k, ret, index;
	index = 0;
	char buf[BUF_SIZE + 1];
	while ((ret = read (fd, buf, BUF_SIZE)) && (buf[index] != '\0')){
		buf[ret] = '\0';
		for (i = 0; i < size; i++){
			for (j = 0; j < 4; i ++){
				for (k = 0; k < 4; k++){
					while (buf[index] == '\n'){
						index ++;
					}
					tab[i][j][k] = buf[index];
					index++;
				}
			}
		}
	}
	if (close(fd) == -1)
		printf("fillit : close() failed.\n");
}


void print_tab (char ***tab, int size)
{
	int i, j;
	for (i = 0; i < size; i++){
		for (j = 0; j < 4; j++){
			printf("%s\n", tab[i][j]);
		}
	}
}



void fillit (int fd)
{
	int size;
	char tab_tetriminos[size][4][4];
	size = pieces_nbr(fd);
	getTetriTab(fd, size, (char ***)tab_tetriminos); 
	


	////////
	print_tab((char ***)tab_tetriminos, size);
	printf("%d\n", size);

}

int main (int argc, char **argv)
{
	if (argc == 1){
		printf("fillit : missing file.\n");
		return 1;
	}
	if (argc > 2){
		printf("fillit : too many arguments.\n");
		return 1;
	}

	int fd;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1){
		printf("fillit : open() failed.\n");
		return 1;
	}
	else {
		fillit(fd);
	}
	if (close(fd) == -1){
		printf("fillit : close() failed.\n");
		return 1;
	}
	return 0;
}