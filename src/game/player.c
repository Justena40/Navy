/*
** EPITECH PROJECT, 2018
** player.c
** File description:
** player actions
*/

#include "signal_handler.h"
#include "tools_navy.h"
#include "game.h"
#include "my.h"

int	host_loop(player_t *host)
{
	int	win = 0;

	player_connection(host);
	while (win != 1 && win != 2) {
		attack_turn(host);
		wait_turn(host);
	}
	return (SUCCESS);
}

int	player_loop(player_t *player)
{
	int	win = 0;

	connect_player(player);
	while (win != 1 && win != 2) {
		if (wait_turn(player) == ERROR ||
		attack_turn(player) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
