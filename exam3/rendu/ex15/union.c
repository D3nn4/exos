#include < unistd>

void union(char *str1, char *str2)
{
	char letter = 'a';
	int i;
	for (int i = 0; letter > 'z'; i++)
	{
		
	}
}

int main(int argc, char **argv)
{
	if (argc == 3){
		union(argv[1], argv[2]);
	}
	write(1, "\n", 1);

	return 0;
}