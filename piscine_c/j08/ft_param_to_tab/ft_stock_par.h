typedef struct s_stock_par
{
int size_param; // longueur param
char *str;		// adresse param
char *copy;		// copy param
char **tab;		// tab retourné par ft_split_whitespace
} 			t_stock_par;