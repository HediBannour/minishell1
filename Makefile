##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	./lib/my_printf/base_convertion.c		\
		./lib/my_printf/call_flag.c				\
		./lib/my_printf/float.c					\
		./lib/my_printf/my_put_nbr.c			\
		./lib/my_printf/my_putchar.c			\
		./lib/my_printf/my_putstr.c				\
		./lib/my_printf/my_strcpy.c				\
		./lib/my_printf/my_strlen.c				\
		./lib/my_strdup.c				\
		./lib/my_printf/scientific_notation.c   \
		./lib/my_printf/my_printf.c				\
		./lib/my_str_to_word_array.c			\
		./lib/my_strcmp.c						\
	 	./src/my_env.c							\
		./src/my_setenv.c						\
		./src/my_unsetenv.c						\
		./src/my_exit.c							\
		./src/my_cd.c							\
		./src/mysh_bis.c						\
		./src/mysh.c



OBJ =	$(SRC:.c=.o)

NAME =	mysh

CFLAGS	+= -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

unit_tests:	fclean all
	rm -f $(OBJ)
	gcc -o unit_tests *.c tests/test.c --coverage -lcriterion

tests_run: unit_tests
	./unit_tests
