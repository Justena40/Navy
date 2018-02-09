/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check if we can play and begin game
*/

#include <stdlib.h>
#include <unistd.h>
#include "tools_navy.h"
#include "init_game.h"
#include "my.h"

static int	player2_game(char *str)
{
	char	**map = NULL;

	map = open_file_and_do_map(str);
	if (map == NULL)
		return (ERROR);
	display_map(map);
//	begin_game_player2(map);
	return (SUCCESS);
}

static int	player1_game(char *str)
{
	char	**map = NULL;

	map = open_file_and_do_map(str);
	if (map == NULL)
		return (ERROR);
	display_map(map);
//	begin_game_player1(map);
	return (SUCCESS);
}

static void	check_pid(int pid)
{
	write(1, "my_pid ", 8);
	my_put_nbrdec(pid);
}

int	game(char **argv)
{
	int	state = 0;
	int	res = 0;
	int pid = getpid();

	if (argv[2] != NULL) {
		check_pid(pid);
		connect_other(pid, &state, argv[1]);
		res = player2_game(argv[2]);
		if (res == ERROR)
			return (ERROR);
	}
	else if (argv[1] != NULL) {
		check_pid(pid);
		connect_host(pid, &state);
		res = player1_game(argv[1]);
		if (res == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
