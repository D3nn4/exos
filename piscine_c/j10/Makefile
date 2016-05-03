NAME = libft.a

SOURCE = srcs/*.c

HEADER = includes/ft.h

all : $(NAME)

$(NAME) :
	gcc -c $(SOURCE)
	ar rc $(NAME) $(HEADER) *.o

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

