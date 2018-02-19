/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check if we can play and begin game
*/

#include <stdbool.h>
#include <stdlib.h>
#include "tools_navy.h"
#include "game.h"
#include "signal_handler.h"
#include "my.h"

static void display_pid(pid_t pid)
{
	my_putstr(1, "my pid: ");
	my_putnbr(pid);
	my_putstr(1, "\n");
}

player_t *init_host(char *map_path)
{
	player_t	*new_host = malloc(sizeof(player_t));

	if (new_host == NULL)
		return (NULL);
	new_host->pid = getpid();
	new_host->enemy_pid = -1;
	new_host->map = open_file_and_do_map(map_path);
	if (new_host->map == NULL)
		return (NULL);
	new_host->enemy_map = init_map();
	if (new_host->enemy_map == NULL)
		return (MALLOC_ERROR);
	display_pid(new_host->pid);
	return (new_host);
}

player_t *init_player(pid_t enemy_pid, char *map_path)
{
	player_t	*new_player = malloc(sizeof(player_t));

	if (new_player == NULL)
		return (NULL);
	new_player->pid = getpid();
	new_player->enemy_pid = enemy_pid;
	new_player->map = open_file_and_do_map(map_path);
	if (new_player->map == NULL)
		return (NULL);
	new_player->enemy_map = init_map();
	if (new_player->enemy_map == NULL)
		return (MALLOC_ERROR);
	display_pid(new_player->pid);
	return (new_player);
}

int	game(int argc, char **argv)
{
	int		res = 0;
	player_t	*player = NULL;

	if (init_signal(&pid_handler) == false)
		return (ERROR);
	if (argc == 2) {
		player = init_host(argv[1]);
		if (player == MALLOC_ERROR)
			return (ERROR);
		if ((res = host_loop(player)) == ERROR)
			return (ERROR);
	}
	else if (argc == 3) {
		player = init_player(my_getnbr(argv[1]), argv[2]);
		if (player == MALLOC_ERROR)
			return (ERROR);
		if ((res = player_loop(player)) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
