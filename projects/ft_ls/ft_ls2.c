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
		}
		else
			current_element = current_element->next;
		closedir(dir);
	}
	return directory_list;
}
void simpleLS (int ac, char *av)
{
	DIR *dir;
		dir  = opendir(av[1]);
		if (dir == NULL){
			printf("ls: cannot access %s: No such file or directory\n", av[1]);
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
		simpleLS(ac, av);		
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
		entry_list = createList (dir)
		ftLsOption (entry_list, struct_data->option_list, stack);
		free(stack);
		stack = NULL;
		freeList (entry_list);
		closedir(dir);
		pullFromList(struct_data->directory_list, struct_data->directory_list->name);
	}
	





}

int main (int argc, char **argv)
{	
	if (argc < 2)
		return 1;
	ftLs(argv, argc);
	return 0;
}