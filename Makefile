##
## EPITECH PROJECT, 2018
## navy
## File description:
## makefile for navy
##

SRC_DIR	=	./src/

INIT_DIR =	$(SRC_DIR)init_game/

MY_DIR	=	$(SRC_DIR)my/

SRC	=	$(SRC_DIR)main.c		\
		$(SRC_DIR)get_next_line.c	\
		$(SRC_DIR)italic_sample.c	\
		$(SRC_DIR)map.c			\
		$(SRC_DIR)connect.c		\
		$(INIT_DIR)check_ship.c		\
		$(INIT_DIR)game.c		\
		$(INIT_DIR)put_ship_in_map.c	\
		$(INIT_DIR)open_and_do_map.c	\
		$(MY_DIR)my_strcmp.c		\
		$(MY_DIR)my_getnbr.c		\
		$(MY_DIR)my_put_nbrdec.c	\
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
