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
		temp_next = malloc(sizeof(*temp_next));
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
	entry_list = malloc(sizeof(*entry_list));
	entry_list->element = NULL;
	entry_list->next_element = NULL;
	dir = opendir(folder);
	if (dir == NULL)
		return NULL;
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
	return new_list;
}

t_stack *popStack (t_stack *stack)
{	
	//t_element *to_remove;
	//to_remove = stack->first_element;
	stack->first_element = stack->first_element->next;
	//free(to_remove->path_name);
	//free(to_remove->next);
	//free(to_remove);
	return stack;


}

t_stack *pushStack (t_stack *stack, char *folder_name)
{	
	t_element *current_element;
	current_element = malloc(sizeof(*current_element));
	//current_element->path_name = '\0';
	//current_element->next = NULL;
	current_element->path_name = malloc(sizeof(folder_name) * strlen(folder_name) + 1);
	current_element->path_name = strcpy(current_element->path_name, folder_name);
	current_element->next = stack->first_element;
	stack->first_element = current_element;
	return stack;
}

char * ft_realloc(char* str, int strSize, int newSize)
{
	char *ptr;
	if (newSize == 0)
		return NULL;
	ptr = malloc(sizeof(*ptr) * newSize + 1);
	if (ptr == NULL){
		return NULL;
	}
	int i = 0;
	for (; i < strSize; i++){
		ptr[i] = str[i];
	}
	while (i < newSize){
		ptr[i] = '\0';
		i++;
	}
	
	free(str);
	return ptr;
}



char *line_creation( int current_len, int next_len, char *next_folder, char *current_folder)
{
	current_folder = ft_realloc(current_folder, current_len, current_len + next_len);
	strncpy(current_folder + current_len, next_folder, next_len);
	return current_folder;
}

void  RecursiveLs(t_stack *stack)
{
	char *current_folder;
	
	current_folder = malloc(sizeof(*current_folder) * strlen (stack->first_element->path_name) + 1);
	current_folder[0] = '\0';
	t_list *current_list;
	current_list = malloc(sizeof(*current_list));	
	while (stack->first_element){
		current_folder = strcpy (current_folder, stack->first_element->path_name);
		popStack (stack);
		printf("%s:\n", current_folder);
		current_list = createList (current_folder);
		printSimpleLs (current_list);
		while (current_list){
			char *file_name = current_list->element->d_name;
			if (current_list->element->d_type == DT_DIR
				&& strcmp(file_name, ".") != 0
				&& strcmp (file_name, "..") != 0){
				char *new_path = NULL;
				new_path = current_folder;
				printf("current_folder : %s\n", current_folder);
				printf("new_path : %s\n", new_path);
				new_path = line_creation(strlen(new_path), strlen(file_name),
								file_name, new_path);
				new_path = line_creation (strlen (new_path), 1, "/", new_path);
				stack = pushStack(stack, new_path);
				printf("new_path modified : %s\n", new_path);
				
			}
			current_list = current_list->next_element;
		}
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
	if ((recu == false))
		printSimpleLs(entry_list);
	
	else
		RecursiveLs (stack);
	
}


t_stack *createStack (char *av)
{
	t_stack *stack;
	stack = malloc(sizeof(*stack));
	stack->first_element = NULL;
	t_element *origin_folder;
	origin_folder = malloc(sizeof(*origin_folder));
	origin_folder->next = NULL;
	origin_folder->path_name = malloc(sizeof(*av) * strlen(av) + 1);
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
	if (argc < 2)
		return 1;
	ftLs(argv, argc);
	return 0;
}