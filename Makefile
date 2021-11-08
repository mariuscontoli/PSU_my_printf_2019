##
## EPITECH PROJECT, 2019
## Makefile my_printf
## File description:
## Will compile our project
##

CC	=	gcc

NAME 	=	libmy.a

SRC	=	src/my_printf.c\
		src/print_chars.c\
		src/print_ints.c\
		src/print_ints2.c\
		src/utils.c\
		src/utils2.c\

LIB =	-I./include

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	$(CC) $(LIB) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $@ $^

clean:
	rm -rf src/*.o

fclean:	clean
	rm -f $(NAME)

re: fclean all
