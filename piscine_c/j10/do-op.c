

int sum(int)
{
	return 0
}

int mult(int)
{
	return 1;
}

typedef struct op_tab {
	char*			op;
	int(*f)(int)	ptr_func;
} op_tab_t;


op_tab_t tab = {{"+", &sum},
				{"*", &mult}};




int main(int argc, **argv)
{

	return 0;
}
