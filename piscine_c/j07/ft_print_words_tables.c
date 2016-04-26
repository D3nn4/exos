void ft_print_words_tables(char **tab)
{
	int i;
	for (i = 0; tab[i] != 0; i++){
		ft_putstr(tab[i]);
		ft_putchar('\n');
	}	
}