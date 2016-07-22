#ifndef __HEADER_H__
#define __HEADER_H__

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../piscine_c/lib/ft.h"

typedef struct 	s_list {
	struct dirent *element;
	struct s_list *next_element;
}				t_list;

typedef struct  s_element {
	char *path_name;
	struct s_element *next;

}				t_element;

typedef struct  s_stack {
	t_element *first_element;
}				t_stack;
#endif