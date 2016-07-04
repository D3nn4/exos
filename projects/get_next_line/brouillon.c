#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include "get_next_line.h"

char * ft_realloc(char* str, int strSize, int newSize)
{
	char *ptr;
	if (newSize == 0)
		return NULL;
	ptr = malloc(sizeof(*ptr) * newSize);
	if (ptr == NULL){
		return NULL;
	}
	int i = 0;
	for (; i < strSize; i++){
		ptr[i] = str[i];
	}
	while (i < newSize){
		ptr[i] = '\0';
		i++;
	}
	
	free(str);
	return ptr;
}


int get_next_line (const int fd, char **line)
{
	int ret, temp_size, i;
	int size = 0;
	static int curseur = 0;
	static char buf[BUFF_SIZE + 1] = "";
	temp_size = size;
	if (buf[0] != 0){
		if (buf[curseur] == '\n'){
			if (buf[curseur + 1] == '\n'){
				*line = ft_realloc(*line, 0, 1);
				ft_strncpy(*line, &buf[curseur], 1);
				curseur++;
				return 1;
			}
			curseur++;
		}
		for (i = curseur; buf[i] != '\n' && buf[i] != '\0' && i < BUFF_SIZE; i++){
			temp_size++;
		}
		*line = ft_realloc(*line, size, temp_size);
		ft_strncpy(*line, buf + curseur, temp_size);
		curseur += temp_size;
		size = temp_size;
		if (buf[i] == '\n' && i < BUFF_SIZE - 1){
			curseur++;
			return 1;
		}
		
	}

	while((ret = read (fd, buf, BUFF_SIZE))){
		buf[ret] = '\0';
		curseur = 0;
		temp_size = size;
		for (i = 0; buf[i] != '\n' && buf[i] != '\0' && i < ret; i++){
			temp_size++;
			curseur++;
		}	
		*line = ft_realloc(*line, size, temp_size);
		ft_strncpy(*line + size, buf, temp_size - size);
		size = temp_size;
		if (curseur == ret)
			curseur = 0;
		if ( i != ret && (buf[i] == '\n' || buf[i] == '\0'))
				return 1;			
	}
	return 0;
}

int main(int argc, char **argv)
{
	int fd = 0;
	if (argc == 2){
		fd = open (argv[1], O_RDONLY);
	}

	char *line = NULL;
	int i = 1;
	while (get_next_line(fd, &line)){
		printf("phrase %d [%s]\n",i, line);
		free(line);
		line = NULL;
	}



	//while (get_next_line(fd, line) == 1)
	//	printf("%s\n", *line);



	return 0;
}