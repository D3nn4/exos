#include <stdbool.h>

#ifndef __FT_H__
#define __FT_H__

bool ft_is_alpha(char letter);
bool ft_is_negative(int n);
char **ft_split(char *str, char *charset);
char **ft_split_whitespaces(char *str);
char *ft_concat_params(int argc, char **argv);
char *ft_strcapitalize(char *str);
char *ft_strcat(char *dest, char *src);
char *ft_strcpy(char *dest, char *src);
char *ft_strdup(char *src);
char *ft_strlowcase(char *str);
char *ft_strncat(char *dest, char *src, int nb);
char *ft_strncpy(char *dest, char *src, unsigned int n);
char *ft_strstr(char *str, char *to_find);
char *ft_strupcase(char *str);
int	ft_atoi(char *str);
int	ft_strlen(char *str);
int ft_count_words(char *str);
int ft_str_is_alpha(char *str);
int ft_str_is_numeric(char *str);
int ft_str_is_printable(char *str);
int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
void ft_print_words_tables(char **tab);
void ft_putchar(char c);
void ft_putnbr(int nb);
void ft_putstr( char *str);
void ft_sort_integer_table(int *tab, int size);
void ft_strrev(char *str);
void ft_swap(int *a, int *b);

#endif