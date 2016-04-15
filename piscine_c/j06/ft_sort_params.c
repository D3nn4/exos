int main(int argc, char **argv)
{

	if (argc > 2){

		int index = 1;
		if (argc == 2){
			ft_putstr(argv[1]);
			return;
		}
		while (index < argc - 1){
			if (ft_strcmp(argv[index], argv[index + 1]) < 1)
			{
				index++;			
			}
			else
			{
				char *a;
				a = argv[index];
				argv[index] = argv[index + 1];
				argv[index + 1] = a;
				index = 0;
			}	
		}
		int i;
		i = 1;
		while (i < argc){
			ft_putstr(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return 0;
}