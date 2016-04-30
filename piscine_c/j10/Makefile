NAME = libft.a

SOURCE = srcs/ft_putchar.c srcs/ft_putstr.c \
		srcs/ft_strcmp.c srcs/ft_strlen.c \
		srcs/ft_swap.c srcs/ft_putnbr.c

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

