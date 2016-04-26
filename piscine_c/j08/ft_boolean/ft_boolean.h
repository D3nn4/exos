

#ifndef __FT_BOOLEAN_H__
#define __FT_BOOLEAN_H__

#include <stdbool.h>
#define t_bool bool
#define EVEN_MSG "J'ai un nombre pair d'arguments.\n"
#define ODD_MSG "J'ai un nombre impair d'arguments.\n"
#define SUCCESS 0
#define FALSE false
#define TRUE true
#define EVEN(x) (x % 2 == 0)

void ft_putstr(char *);
char write(int, char *, int);
bool ft_is_even(int);
char *putstr(char *);

#endif