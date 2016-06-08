NAME = fillit

SRC = ./includes/*.c

HEADER = ./includes/header.h

all : $(NAME)

$(NAME) :
	gcc -c $(SRC)
	gcc -ggdb3 -Wall -Wextra -Werror -o $(NAME) $(HEADER) *.o

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all