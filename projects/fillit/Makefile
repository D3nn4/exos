NAME = fillit

SRC = ./includes/*.c

HEADER = ./includes/header.h

all : $(NAME)

$(NAME) :
	gcc -ggdb3 -Wall -Wextra -c $(SRC)
	gcc -o $(NAME) $(HEADER) *.o

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all