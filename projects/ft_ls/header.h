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
	char *name;
	struct s_element *next;

}				t_element;

typedef struct  s_stack {
	t_element *first_element;
}				t_stack;

typedef struct s_data {
	t_element *option_list;
	t_element *directory_list;
}				t_data;


void ftLs (int ac, char **av);
void simpleLS (char *av);
void freeList (t_list *list);
void printFiles (t_list *list);
void addSeparator (char *string);
void RecursiveLs(t_stack *stack, t_element *option_list);
void RecursiveLs(t_stack *stack, t_element *option_list);
t_data *findDirAndOptions (int ac, char **av);
t_element *validDirectory (t_element *directory_list);
t_data *createStruct ();
t_element *pushFrontList (char *element_name, t_element *first_element);
t_element *pullFromList (t_element *element_list, char *element_name);
t_stack *stackFromList (t_list *list, t_stack *stack, char *folder);
t_stack *stackFromList (t_list *list, t_stack *stack, char *folder);
t_stack *popStack (t_stack *stack);
t_stack *pushStack (t_stack *stack, char *folder_name);
t_stack *createStack (char *av);
t_list *ftLsOption (t_list *entry_list, t_element *option_list);
t_list *reverseList (t_list *list);
t_list *createList (DIR *dir);
t_list *structList (DIR *dir, t_list *begin_list);
t_list *sortList (t_list *list);
t_list *findPlace (t_list *to_sort, t_list *list);
int compare (char *name1, char *name2);
char *allInMin (char *string, int size);






#endif