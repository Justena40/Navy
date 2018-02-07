##
## EPITECH PROJECT, 2018
## navy
## File description:
## makefile for navy
##

SRC_DIR	=	./src/

MY_DIR	=	$(SRC_DIR)my/

SRC	=	$(SRC_DIR)main.c		\
		$(SRC_DIR)get_next_line.c	\
		$(SRC_DIR)check_ship.c		\
		$(SRC_DIR)map.c			\
		$(SRC_DIR)game.c		\
		$(SRC_DIR)put_ship_in_map.c	\
		$(SRC_DIR)open_and_do_map.c	\
		$(MY_DIR)my_strcmp.c		\
		$(MY_DIR)my_strlen.c		\
		$(MY_DIR)my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-I ./include -Wall -Wextra -g

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
