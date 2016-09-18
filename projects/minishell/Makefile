NAME = minishell

SRC = minishell.c main.c echo.c env.c struct.c cd.c lib_function.c

HEADER = .

LIB_DIR = ../../piscine_c/lib

all : $(NAME)

$(NAME) : 
	gcc -ggdb3 -Wall -Wextra -I$(HEADER) -I$(LIB_DIR) -c $(SRC)
	gcc -o $(NAME)   *.o -lft -L$(LIB_DIR)

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re ft_ls