#include "ft_list.h"

void ft_print_elem(void *data)
{
	if (data == NULL){
		printf("No data\n");
		return;
	}
	printf("%s\n",(char*)data);
}