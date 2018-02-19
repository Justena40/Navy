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
		if (attack_turn(host) == ERROR)
			return (ERROR);
		wait_turn(host);
		my_putstr(1, "\nmy positions:\n");
		display_map(host->map);
		my_putstr(1, "\nenemy's positions:\n");
		display_map(host->enemy_map);
	}
	return (SUCCESS);
}

int	player_loop(player_t *player)
{
	int	win = 0;

	connect_player(player);
	while (win != 1 && win != 2) {
		wait_turn(player);
		if (attack_turn(player) == ERROR)
			return (ERROR);
		my_putstr(1, "\nmy positions:\n");
		display_map(player->map);
		my_putstr(1, "\nenemy's positions:\n");
		display_map(player->enemy_map);
	}
	return (SUCCESS);
}
