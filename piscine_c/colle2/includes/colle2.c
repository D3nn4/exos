#include <stdio.h>
#include "./header.h"
#include <stdbool.h>

#define BUF_SIZE 4096

int widht (char *buf)
{
	int i, widht;
	widht = 0;
	for (i = 0; buf[i] != '\n'; i++) {
		widht++;
	}
	return widht;
}

int height (char *buf)
{
	int i, height;
	height = 0;
	for (i = 0; buf[i] != '\0'; i++) {
		if (buf[i] == '\n')
			height++;
	}
	return height;
}

char **getTabFromBuffer(char *buf, int widht, int height)
{
  // tu crees ton tableau par rapport a ce que tu as reads
	char **tab2D;
	int i, j, buf_ind;
	buf_ind = 0;
	j = 0;
	tab2D = malloc(sizeof(*tab2D) * height);
	while (buf[buf_ind] != '\0'){
		for (i = 0; i < height; i++ ){
			tab2D[i] = malloc(sizeof(**tab2D) * widht + 1);
			while (buf[buf_ind] != '\n'){
				tab2D[i][j] = buf[buf_ind];
				j++;
				buf_ind++;
			}
			buf_ind++;
			tab2D[i][j] = '\0';
			j = 0;
		}
	}
	return tab2D;
}

void find_colle ()
{
	char buf[BUF_SIZE + 1];
	char **tab2D;
	int ret, w, h;
	ret = read(0, buf, BUF_SIZE);
	buf[ret] = '\0';
	w = widht(buf);
	h = height(buf);
	tab2D = getTabFromBuffer(buf, w, h);
	checkall(tab2D, w, h);
	
	/*
	printf("height = %d & widht = %d\n", h, w);
	int i;
	for (i = 0; i < h; i++){
		printf("%s\n", tab2D[i]);
	}
	*/
}



int main ()
{
	find_colle();


	
	return 0;
}