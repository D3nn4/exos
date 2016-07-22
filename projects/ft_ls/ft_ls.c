#include "header.h"
#include "ft.h"

//static int number = 0;



void printSimpleLs (t_list *list)
{
	if (list == NULL){
		printf("\n");
		return;
	}
	while (list){
		if (strncmp(list->element->d_name, ".", 1) != 0)
			printf("%s\n", list->element->d_name);
		list = list->next_element;
	}

}



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
	free(min_name2);
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
		temp_next = malloc(sizeof(temp_next));
		temp_next->element = current_entry;
		temp_next->next_element = NULL;
		temp_current->next_element = temp_next;
		temp_current = temp_next;
	}
	return sortList (begin_list);
}

t_list *createList (char *folder)
{
	DIR *dir;
	t_list *entry_list;
	entry_list = malloc(sizeof(entry_list));
	entry_list->element = NULL;
	entry_list->next_element = NULL;
	dir = opendir(av[ac - 1]);
	if (dir == NULL)
		return NULL;
	entry_list = structList(dir, entry_list);
	closedir(dir);
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
	return new_list;
}

t_stack *popStack (t_stack *stack)
{	
	t_element *to_remove;
	to_remove = stack->first_element;
	stack->first_element = stack->first_element->next;
	free(to_remove->path_name);
	free(to_remove->next);
	free(to_remove);
	return stack;
}

t_stack *pushStack (t_stack *stack, char *folder_name)
{	
	t_element *current_element;
	current_element->path_name = '\0';
	current_element->next = NULL;
	current_element->path_name = malloc(sizeof(folder_name) * strlen(folder_name));
	current_element->path_name = strcpy(current_element->path_name, folder_name);
	current_element->next = stack->first_element;
	stack->first_element = current_element;
	return stack;
}


void  RecursiveLs(t_stack *stack)
{
	char *current_folder;
	while (stack->first_element){
		current_folder = stack->first_element->path_name;
		printf("%s\n", current_folder);
		printSimpleLs (createList (current_folder));


	}

	return;

	

}


void ftLsOption (t_list *entry_list, char **av, int ac, t_stack *stack)
{
	bool recu = false;
	
	int i;
	for (i = 1; i < ac; i++){
		if (strcmp(av[i], "-r") == 0)
			entry_list = reverseList(entry_list);
		if (strcmp(av[i], "-R") == 0){
			recu = true;
		}
	}
	if ((recu = false))
		printSimpleLs(entry_list);
	
	else
		RecursiveLs (entry_list, stack);
	
}

t_stack *createStack (char *av)
{
	t_stack *stack;
	stack->first_element = NULL;
	t_element *origin_folder;
	origin_folder->path_name = '\0';
	origin_folder->next = NULL;
	origin_folder->path_name = malloc(sizeof(*av) * strlen(av));
	if (origin_folder == NULL)
		return NULL;
	origin_folder->path_name = strcpy(origin_folder->path_name, av);
	stack->first_element = origin_folder;
	return stack;
}



void ftLs (char **av, int ac)
{
	t_stack *stack;
	stack = createStack(av[ac - 1]);
	if (stack == NULL) {
		printf("error creation stack\n");
		return;
	}
	t_list *entry_list;
	entry_list = createList(av[ac - 1]);
	if ((entry_list == NULL))
		return;	
	if ((ac > 2))
		ftLsOption(entry_list, av, ac, stack);
	else 
		printSimpleLs(entry_list);
}

int main (int argc, char **argv)
{	
	if (argc < 2){
		return 1;
	}
	ftLs(argv, argc);



	return 0;
}