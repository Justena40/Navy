/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check if we can play and begin game
*/

#include <stdlib.h>
#include "tools_navy.h"
#include "init_game.h"

static int	player2_game(char *str)
{
	char	**map = NULL;

	map = open_file_and_do_map(str);
	if (map == NULL)
		return (ERROR);
//	begin_game_player2(map);
	return (SUCCESS);
}

static int	player1_game(char *str)
{
	char	**map = NULL;

	map = open_file_and_do_map(str);
	if (map == NULL)
		return (ERROR);
//	begin_game_player1(map);
	return (SUCCESS);
}

int	game(char **argv)
{
	int	res = 0;

	if (argv[2] != NULL) {
		res = player2_game(argv[2]);
		if (res == ERROR)
			return (ERROR);
	}
	else if (argv[1] != NULL) {
		res = player1_game(argv[1]);
		if (res == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
