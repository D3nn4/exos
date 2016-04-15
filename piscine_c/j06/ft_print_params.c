int main (int argc, char **argv)
{
	if (argc > 2)
	{
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