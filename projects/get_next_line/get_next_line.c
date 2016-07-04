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

int str_lenght (char *buf)
{
	int i, size;
	size = 0;
	for (i = 0; buf[i] != '\n' && buf[i] != '\0'; i++){
		size++;
	}
	return size;
}

void line_creation( int size, int curseur, char *buf, char **line)
{
	*line = ft_realloc(*line, size, size + curseur);
	ft_strncpy(*line + size, buf, curseur);
}


int get_next_line (const int fd, char **line)
{
	int ret, currentLineSize;
	currentLineSize = 0;
	static int curseur = 0;
	static char buf[BUFF_SIZE + 1] = "";
	if (buf[0] != 0){
		if (buf[curseur] == '\n'){
			if (buf[curseur + 1] == '\n'){
				line_creation (0, 1, &buf[curseur], line);
				curseur++;
				return 1;
			}
			curseur++;
		}
		if (buf[curseur + 1]){
			int tempbufIndex;
			tempbufIndex = curseur;
			curseur = str_lenght (&buf[curseur]);
			line_creation (currentLineSize, curseur, &buf[tempbufIndex], line);
			currentLineSize = curseur;
			curseur += tempbufIndex;

			if (buf[curseur + 1] == '\0')
				buf[0] = 0;
			if (buf[curseur] == '\n' || buf[curseur] == '\0'){
				if (buf[curseur + 1] == '\0')
					buf[0] = 0;

				return 1;
			}

		}
	}
	while ((ret = read (fd, buf, BUFF_SIZE))){
		buf[ret] = '\0';
		curseur = str_lenght (buf);
		line_creation(currentLineSize, curseur, buf, line);
		currentLineSize += curseur;
		if (curseur == ret)
			curseur = 0;
		if (buf[curseur] == '\n'){
			if (curseur == ret)
				buf[0] = 0;
			return 1;
		}
	}
	return 0;
}

int get_next_line2 (const int fd, char **line)
{	
	int ret, currentLineSize, newSize;
	currentLineSize = 0;
	static int curseur = 0;
	static char buf[BUFF_SIZE + 1] = "";
	if (buf[0] == 0){
		ret = read (fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if ((ret = 0))
			return 0;
	}
	while (true){
		if (buf[curseur] == '\n'){
			if (buf[curseur + 1] == '\n'){
				line_creation (0, 1, &buf[curseur], line);
				curseur++;
				return 1;
			}
			curseur++;
		}
		newSize = str_lenght(&buf[curseur]);
		line_creation(currentLineSize, newSize, &buf[curseur], line);
		curseur +=newSize;
		currentLineSize += newSize;
		if ( buf[curseur] == '\n')
			return 1;
		if (buf[curseur] == '\0'){
			if (buf[curseur + 1] == '\0')
				return 0;
			curseur = 0;
			buf[0] = 0;
			return 1;
		}
	}
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
		i++;
	}
	

	/*
	get_next_line2(fd, &line);
	printf("[%s]\n", line);
	*/


	return 0;
}