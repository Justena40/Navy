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
#include "play_game.h"
#include "my.h"

static int	player2_game(char *pid_enn, char *str)
{
	char	**my_map = NULL;

	my_map = open_file_and_do_map(str);
	if (my_map == NULL)
		return (ERROR);
	begin_game_player2(my_map, my_getnbr(pid_enn));
	return (SUCCESS);
}

static int	player1_game(char *str, int pid_enn)
{
	char	**my_map = NULL;

	my_map = open_file_and_do_map(str);
	if (my_map == NULL)
		return (ERROR);
	begin_game_player1(my_map, pid_enn);
	return (SUCCESS);
}

static void	check_pid(int pid)
{
	write(1, "my pid: ", 9);
	my_put_nbrdec(pid);
}

int	game(char **argv)
{
	int	res = 0;
	int pid = getpid();
	int	pid_enn = 0;

	if (argv[2] != NULL) {
		check_pid(pid);
		connect_other(argv[1]);
		res = player2_game(argv[1], argv[2]);
		if (res == ERROR)
			return (ERROR);
	}
	else if (argv[1] != NULL) {
		check_pid(pid);
		pid_enn = connect_host(pid);
		res = player1_game(argv[1], pid_enn);
		if (res == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
