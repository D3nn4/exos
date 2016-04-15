int main (int argc, char **argv)
{
	if (argc > 2)
	{
		int i;
		i = argc - 1;
		while (i > 0){
			ft_putstr(argv[i]);
			ft_putchar('\n');
			i--;
		}
	}
	return 0;
}