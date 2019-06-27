NAME = libft.a
SOURCE = *.c
HEADER = libft.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(HEADER) $(SOURCE)
	ar rc $(NAME) *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm $(NAME)

re: fclean all
