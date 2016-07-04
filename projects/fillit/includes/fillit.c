#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "header.h"

#define BUF_SIZE 4096


int pieces_nbr (int fd)
{
	int ret, size = 0;
	char buf[BUF_SIZE + 1]; 
	while ((ret = read(fd, buf, BUF_SIZE))){
		buf[ret] = '\0';
		int i;
		for (i = 0; buf[i] != '\0'; i++){
			if (buf[i] == '\n' && buf[i - 1] == '\n')
				size++;
		}
	}
	return size + 1;
}

void getTetriTab (int fd, int size, char tab[][4][4])
{
	int i, j, k, ret, index, nbr_of_sharp;
	index = 0;
	nbr_of_sharp = 0;
	char buf[BUF_SIZE + 1];
	while ((ret = read (fd, buf, BUF_SIZE)) && (buf[index] != '\0')){
		buf[ret] = '\0';
		for (i = 0; i < size; i++){
			for (j = 0; j < 4; j++){
				for (k = 0; k < 4; k++){
					if (buf[index] == '.' || buf[index] == '#'){
						if (buf[index] == '#')
							nbr_of_sharp++;
						if (nbr_of_sharp > 4)
							return;
						tab[i][j][k] = buf[index];
						index++;
					}
					else
						return;
				}
				if (buf[index] == '\n')
						index++;
				else
					return;
			}
			nbr_of_sharp = 0;
			if (i < size - 1 && buf[index] == '\n' )
				index++;
			else 
				return;
		}
	}
}


void print_tab (char tab[][4][4], int size)
{
	int i, j, k;
	for (i = 0; i < size; i++){
		for (j = 0; j < 4; j++){
			for (k = 0; k < 4; k++){
				printf("%c", tab[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}



void fillit (char *av)
{
	int fd = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1){
		printf("fillit : open() failed.\n");
		return;
	}
	int size = 0;
	size = pieces_nbr(fd);
	if (close(fd) == -1){
		printf("fillit : close1() failed.\n");
		return;
	}
	char tab_tetriminos[size][4][4];
	fd = open(av, O_RDONLY);
	if (fd == -1){
		printf("fillit : open() failed.\n");
		return ;
	}
	getTetriTab(fd, size, tab_tetriminos);
	if (close(fd) == -1){
		printf("fillit : close2() failed.\n");
		return ;
	}
	t_offset *tab_form;
	tab_form = malloc(sizeof(*tab_form) * size);
	
	checkAll(tab_tetriminos, size, tab_form);

	////////
	int nbr = 0;
	while (nbr < size){
		printf("%s\n",tab_form[nbr].str );
		nbr++;
	}

	
	
	printf("nb de tetrominos : %d\n", size);

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
	fillit(argv[1]);
	
	
	return 0;
}