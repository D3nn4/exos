#include "header.h"
#include "ft.h"

char *allInMin (char *string, int size)
{
	char *string_min;
	string_min = malloc(sizeof(string_min) * size + 1);
	if (string_min == NULL){
		printf("error\n");
		return NULL;
	}
	int i;
	int maj_to_min = 32;
	for (i = 0; i < size; i++){
		if ('A' <= string[i] && string[i] <= 'Z')
			string_min[i] = string[i] + maj_to_min;
		else
			string_min[i] = string[i];
	}
	string_min[size] = '\0';
	return string_min;
}

int compare (char *name1, char *name2)
{
	int size1 = strlen(name1);
	int size2 = strlen(name2);
	int comp;
	char *min_name1;
	char *min_name2;
	min_name1 = allInMin(name1, size1);
	min_name2 = allInMin(name2, size2);
	comp = strcmp(min_name1, min_name2);

	free(min_name1);
	min_name1 = NULL;
	free(min_name2);
	min_name2 = NULL;

	
	return comp;

}

t_list *findPlace (t_list *to_sort, t_list *list)
{
	t_list *first = list;
	t_list *temp_current = list;
	t_list *temp_next = list->next_element;
	while (to_sort){
		if (compare(to_sort->element->d_name, temp_current->element->d_name) == 1 
			&& temp_next == NULL){
			temp_current->next_element = to_sort;
			to_sort->next_element = NULL;
			break;
		}
		if (compare(to_sort->element->d_name, temp_current->element->d_name) == 1 
			&& compare(temp_next->element->d_name, to_sort->element->d_name) == 1){
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
		if (compare(temp_current->element->d_name, temp_next->element->d_name) == 1){
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
		temp_next = malloc(sizeof(*temp_next));
		temp_next->element = current_entry;
		temp_next->next_element = NULL;
		temp_current->next_element = temp_next;
		temp_current = temp_next;
	}
	return sortList (begin_list);
}

t_list *createList (DIR *dir)
{
	
	t_list *entry_list;
	entry_list = malloc(sizeof(*entry_list));
	entry_list->element = NULL;
	entry_list->next_element = NULL;
	entry_list = structList(dir, entry_list);	
	return entry_list;

}

t_list *reverseList (t_list *list)
{
	if (list->next_element == NULL)
		return list;
	t_list *new_list = NULL;
	while (list){
		t_list *temp_next = list->next_element;
		list->next_element = new_list;
		new_list = list;
		list = temp_next;
	}
	
	list = NULL;
	return new_list;
}

void freeList (t_list *list)
{
	t_list *to_remove;
	while (list)
	{
		to_remove = list;
		list = list->next_element;
		to_remove->next_element = NULL;
		free(to_remove);
		to_remove = NULL;
	}
}