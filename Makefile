SRC = conversions/*.c      utils/*.c \
checkflags.c ft_printf.c

OBJSRC = *.o

CC = gcc -Wall -Wextra -Werror 

NAME = libftprintf.a


all: $(NAME)

$(NAME) : $(SRC)
	$(CC) -c $(SRC) -I.
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)

clean : 
	-rm -f $(OBJSRC)

fclean : clean
	rm  -f $(NAME)

re : fclean all
