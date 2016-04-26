#include <stdbool.h>

bool ft_is_alpha(char letter)
{
	return ('a' <= letter && letter <= 'z'
			|| 'A' <= letter && letter <= 'Z');
}