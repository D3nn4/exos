NAME = ft_tail

SRC = ../ex00/includes/*.c
SRC2 = ./includes/*.c

all: $(NAME)

$(NAME):
	gcc -c $(SRC) $(SRC2)
	gcc -o $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all