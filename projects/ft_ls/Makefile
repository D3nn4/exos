NAME = ft_ls

SRC = ft_ls.c

HEADER = .

LIB_DIR = ../../piscine_c/lib



all : $(NAME)

$(NAME) : 
	gcc -ggdb3 -Wall -Wextra -I$(HEADER) -I$(LIB_DIR) -c $(SRC)
	gcc -o $(NAME)   *.o

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re ft_ls