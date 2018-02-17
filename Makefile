##
## EPITECH PROJECT, 2018
## navy
## File description:
## makefile for navy
##

SRC_DIR	=	./src/

GAME_DIR =	$(SRC_DIR)game/

MY_DIR	=	$(SRC_DIR)my/

PLA_DIR =	$(SRC_DIR)player/

SRC	=	$(SRC_DIR)main.c		\
		$(SRC_DIR)get_next_line.c	\
		$(SRC_DIR)signal_handler.c	\
		$(SRC_DIR)italic_text.c		\
		$(GAME_DIR)game.c		\
		$(GAME_DIR)open_and_do_map.c	\
		$(GAME_DIR)put_ship_in_map.c	\
		$(GAME_DIR)map.c		\
		$(GAME_DIR)player.c		\
		$(GAME_DIR)player_connection.c	\
		$(GAME_DIR)game_command.c	\
		$(GAME_DIR)input.c		\
		$(GAME_DIR)check_ship.c		\
		$(GAME_DIR)encryption.c		\
		$(GAME_DIR)check_in_map.c	\
		$(MY_DIR)my_strcmp.c		\
		$(MY_DIR)my_getnbr.c		\
		$(MY_DIR)my_putnbr.c		\
		$(MY_DIR)my_strlen.c		\
		$(MY_DIR)my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-I ./include -g -Wall -W -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
