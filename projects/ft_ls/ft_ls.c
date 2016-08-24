#include "header.h"
#include "ft.h"

void printFiles (t_list *list)
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

<<<<<<< HEAD
t_data *findDirAndOptions (int ac, char **av)
{
	t_data *struct_data;
	struct_data = createStruct ();
	int i;
	bool recursif = false;
	for (i = 1; i < ac; i++){
		
		if (strncmp(av[i], "-",1) == 0){
			if (strcmp (av[i], "-R") == 0)
				recursif = true;
			else
				struct_data->option_list = pushFrontList (av[i], struct_data->option_list);
		}
		else
			struct_data->directory_list = pushFrontList (av[i], struct_data->directory_list);
	}
	if (recursif == true){
		struct_data->option_list = pushFrontList ("-R", struct_data->option_list);
	}
	return struct_data;
}

t_element *validDirectory (t_element *directory_list)
{
	t_element *current_element;
	current_element = directory_list;
	while (current_element){
		DIR *dir;
		dir = opendir (current_element->name);
		if (dir == NULL){
			t_element *temp;
			temp = current_element->next;
			printf("ls: cannot access %s: No such file or directory\n", current_element->name);
			directory_list = pullFromList (directory_list, current_element->name);
			current_element = temp;
			temp = NULL;
		}
		else
			current_element = current_element->next;
		closedir(dir);
	}
	current_element = NULL;
	return directory_list;
}

=======
>>>>>>> 61586b707ef8cc2e8e1c63bccd1063debef2abd2
void addSeparator (char *string)
{
	int size;
	size = strlen (string);
	if ((string[size - 1] == '/'))
		return;
	else
		strcat(string, "/");
}

<<<<<<< HEAD


void RecursiveLs(t_stack *stack, t_element *option_list)
=======
t_stack *stackFromList (t_list *list, t_stack *stack, char *folder)
{
	while (list){
		char *file_name = list->element->d_name;
		if (list->element->d_type == DT_DIR
				&& strcmp(file_name, ".") != 0
				&& strcmp (file_name, "..") != 0){
				char *new_path = NULL;   
				new_path = malloc(sizeof(*new_path) * (strlen(folder) + 1 + strlen(file_name) + 1));
				strcpy(new_path, folder);
				addSeparator(new_path);
				strcat(new_path, file_name);				
				stack = pushStack(stack, new_path);
				free(new_path);
				new_path = NULL;
		}
		list = list->next_element;
	}
	free(folder);
	folder = NULL;
	return stack;
}

void RecursiveLs(t_stack *stack)
>>>>>>> 61586b707ef8cc2e8e1c63bccd1063debef2abd2
{
	char *current_folder = NULL;
	t_list *current_list;
	t_list *begin_list;	
	while (stack->first_element){
<<<<<<< HEAD
		current_folder = malloc(sizeof(*current_folder) * strlen(stack->first_element->name) + 1);
		current_folder = strcpy (current_folder, stack->first_element->name);
=======
		current_folder = malloc(sizeof(*current_folder) * strlen(stack->first_element->path_name) + 1);
		current_folder = strcpy (current_folder, stack->first_element->path_name);
>>>>>>> 61586b707ef8cc2e8e1c63bccd1063debef2abd2
		printf("%s:\n", current_folder);
		DIR *dir;
		dir = opendir(current_folder);
		if (dir == NULL){
		printf("ERROR OPENDIR %s\n", current_folder);
		return;
		}
		current_list = createList (dir);
		//
		current_list = ftLsOption(current_list, option_list);
		//
		printFiles(current_list);
		popStack (stack);
		printf("\n");
		current_list = reverseList (current_list);
		begin_list = current_list;
		stack = stackFromList (current_list, stack, current_folder);
		freeList(begin_list);
		begin_list = NULL;
		closedir(dir);
	}
	return;
}

<<<<<<< HEAD
t_list *ftLsOption (t_list *entry_list, t_element *option_list)
{
	t_element *current_option = option_list;
	while (current_option){
		if (strcmp (current_option->name, "-r") == 0)
			entry_list = reverseList(entry_list);
		current_option = current_option->next;
	}
	current_option = NULL;
	return entry_list;
=======
t_list *optionList ()
{
	
}

void ftLsOption (t_list *entry_list, char **av, int ac, t_stack *stack)
{
	bool recu = false;
	t_list *option_list;
	
	
	int i;
	for (i = 1; i < ac; i++){
		if (strcmp(av[i], "-r") == 0)
			entry_list = reverseList(entry_list);
		if (strcmp(av[i], "-R") == 0)
			recu = true;
	}
	if ((recu == false))
		printSimpleLs(entry_list);
	else
		RecursiveLs (stack);
>>>>>>> 61586b707ef8cc2e8e1c63bccd1063debef2abd2
}

void simpleLS (char *av)
{
	DIR *dir;
		dir  = opendir(av);
		if (dir == NULL){
			printf("ls: cannot access %s: No such file or directory\n", av);
			return;
		}
		t_list *entry_list;
		entry_list = createList(dir);
		printFiles (entry_list);
		freeList (entry_list);
		closedir (dir);
		return;
}


void ftLs (int ac, char **av)
{
	if (ac == 2){
		simpleLS(av[1]);		
		return;
	}
	t_data *struct_data;
	struct_data = findDirAndOptions (ac, av);
	struct_data->directory_list = validDirectory (struct_data->directory_list);
	while (struct_data->directory_list){
		t_stack *stack = createStack(struct_data->directory_list->name);
		if (stack == NULL) {
			printf("error creation stack\n");
			return;
		}
		t_list *entry_list;
		DIR *dir = opendir (struct_data->directory_list->name);
		if (dir == NULL)
			printf("error opening dir %s\n", struct_data->directory_list->name);
		entry_list = createList (dir);
		
		if (struct_data->option_list != NULL){
			if (strcmp (struct_data->option_list->name, "-R") == 0)
				RecursiveLs(stack, struct_data->option_list);
			else{
				entry_list = ftLsOption (entry_list, struct_data->option_list);
				printFiles (entry_list);
			}
		}
		else 
			printFiles (entry_list);
		free(stack);
		stack = NULL;
		freeList (entry_list);
		closedir(dir);
		struct_data->directory_list = pullFromList(struct_data->directory_list, struct_data->directory_list->name);
	}
<<<<<<< HEAD
=======
	if ((ac > 2))
		ftLsOption(entry_list, av, ac, stack);
	else 
		printSimpleLs(entry_list);
	free(stack);
	stack = NULL;
	freeList (entry_list);
	closedir(dir);
>>>>>>> 61586b707ef8cc2e8e1c63bccd1063debef2abd2
}


int main (int argc, char **argv)
{	
	if (argc < 2)
		return 1;
	ftLs(argc, argv);
	return 0;
}
