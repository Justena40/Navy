/*
** EPITECH PROJECT, 2018
** player.c
** File description:
** player actions
*/

#include <stdbool.h>
#include "signal_handler.h"
#include "tools_navy.h"
#include "game.h"
#include "my.h"

int	host_loop(player_t *host)
{
	int	win = 21;

	player_connection(host);
	while (win != 0) {
		if (attack_turn(host) == ERROR)
			return (ERROR);
		if (check_win(host->enemy_map) == true) {
			kill(host->enemy_pid, SIGUSR2);
			return (1);
		}
		wait_turn(host);
		if (check_win(host->map) == true)
			return (0);
		my_putstr(1, "\nmy positions:\n");
		display_map(host->map);
		my_putstr(1, "\nenemy's positions:\n");
		display_map(host->enemy_map);
	}
	return (win);
}

int	player_loop(player_t *player)
{
	int	win = 21;

	connect_player(player);
	while (win != 0) {
		wait_turn(player);
		if (check_win(player->map) == true)
			return (0);
		if (attack_turn(player) == ERROR)
			return (ERROR);
		if (check_win(player->enemy_map) == true) {
			kill(player->enemy_pid, SIGUSR2);
			return (1);
		}
		my_putstr(1, "\nmy positions:\n");
		display_map(player->map);
		my_putstr(1, "\nenemy's positions:\n");
		display_map(player->enemy_map);
	}
	return (win);
}
