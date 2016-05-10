NAME = libft.a

SOURCE = ft_*.c

HEADER = ft_list.h


all : $(NAME)

$(NAME) : 
	gcc -c $(SOURCE) $(HEADER)
	ar rc $(NAME)  *.o

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
