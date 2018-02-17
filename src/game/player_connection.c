/*
** EPITECH PROJECT, 2018
** navy
** File description:
** connection of players
*/

#include "player.h"
#include "tools_navy.h"
#include "signal_handler.h"
#include "game.h"
#include "my.h"

int	connect_player(player_t *player)
{
	kill(player->enemy_pid, SIGUSR1);
	if (init_signal(&sig_handle) == false)
		return (ERROR);
	my_putstr(1, "successfully connected\n");
	my_putstr(1, "\nmy positions:\n");
	display_map(player->map);
	my_putstr(1, "\nenemy's positions:\n");
	display_map(player->enemy_map);
	return (SUCCESS);
}

int	player_connection(player_t *host)
{
	my_putstr(1, "waiting for enemy connection...\n\n");
	pause();
	host->enemy_pid = rec_sig;
	if (init_signal(&sig_handle) == false)
		return (ERROR);
	my_putstr(1, "enemy connected\n");
	my_putstr(1, "\nmy positions:\n");
	display_map(host->map);
	my_putstr(1, "\nenemy's positions:\n");
	display_map(host->enemy_map);
	return (SUCCESS);
}
