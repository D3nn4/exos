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

char *allInMin (char *string, int size);
int compare (char *name1, char *name2);
t_list *findPlace (t_list *to_sort, t_list *list);
t_list *sortList (t_list *list);
t_list *structList (DIR *dir, t_list *begin_list);
t_list *createList (char *folder);
t_list *reverseList (t_list *list);
t_stack *popStack (t_stack *stack);
t_stack *pushStack (t_stack *stack, char *folder_name);
t_stack *createStack (char *av);



#endif