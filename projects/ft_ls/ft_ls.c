#include "header.h"
#include "ft.h"

static int number = 0;

void printSimpleLs (t_list *list)
{

	while (list){
		if (strncmp(list->element->d_name, ".", 1) != 0)
			printf("%s\n", list->element->d_name);
		list = list->next_element;
	}
}

t_list *findPlace (t_list *to_sort, t_list *list)
{
	/*  POUR MON DEBUGGAGE NE FAIT PAS PARTIE DU CODE
	printf("findPlace : to_sort : %s\n", to_sort->element->d_name);
	printf("%d\n", number);
	number++;
	printSimpleLs(list);
	*/
	t_list *first = list;
	t_list *temp_current = list;
	t_list *temp_next = list->next_element;
	while (to_sort){
		if (strcmp(to_sort->element->d_name, temp_current->element->d_name) == 1 
			&& temp_next == NULL){
			temp_current->next_element = to_sort;
			to_sort->next_element = NULL;
			break;
		}
		if (strcmp(to_sort->element->d_name, temp_current->element->d_name) == 1 
			&& strcmp(temp_next->element->d_name, to_sort->element->d_name) == 1){
			to_sort->next_element = temp_next;
			temp_current->next_element = to_sort;
			break;
		}
		temp_current = temp_next;
		temp_next = temp_next->next_element;
	}

	return first;
}

t_list *sortList (t_list *list)
{	
	t_list *first = list;
	t_list *temp_previous = NULL;
	t_list *temp_current = list;
	t_list *temp_next = list->next_element;
	t_list *to_sort = NULL;
	
	while (temp_next){
		if (strcmp(temp_current->element->d_name, temp_next->element->d_name) == 1){
			to_sort = temp_current;
			if (temp_previous == NULL)
				first = temp_next;
			else 
				temp_previous->next_element = temp_next;
			first = findPlace(to_sort, first);
			to_sort = NULL;
			temp_previous = NULL;
			temp_current = list;
			temp_next = list->next_element;

		}
		else {
			temp_previous = temp_current;
			temp_current = temp_next;
			temp_next = temp_next->next_element;
		}
			
	}
	return first;
}

t_list *structList (DIR *dir, t_list *begin_list)
{
	struct dirent *current_entry;
	t_list *temp_next;
	t_list *temp_current;
	begin_list->element = readdir(dir);
	temp_current = begin_list;
	while((current_entry = readdir(dir)) != NULL){
		temp_next = malloc(sizeof(temp_next));
		temp_next->element = current_entry;
		temp_next->next_element = NULL;
		temp_current->next_element = temp_next;
		temp_current = temp_next;
	}
	printSimpleLs(begin_list);
	printf("\n\n\n");
	return sortList (begin_list);
}



void ft_ls (char *av)
{
	DIR *dir;
	t_list *entry_list;
	entry_list = malloc(sizeof(entry_list));
	entry_list->element = NULL;
	entry_list->next_element = NULL;
	dir = opendir(av);
	entry_list = structList(dir, entry_list);
	

	printSimpleLs(entry_list);
	
	closedir(dir);
}

int main (int argc, char **argv)
{	
	if (argc != 2){
		return 1;
	}
	ft_ls(argv[1]);



	return 0;
}