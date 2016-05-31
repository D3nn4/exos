NAME = ft_display_file

SRC = ./includes/*.c

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	gcc -o $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all