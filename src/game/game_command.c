/*
** EPITECH PROJECT, 2018
** navy
** File description:
** player commands
*/

#include "my.h"
#include "signal_handler.h"
#include "tools_navy.h"
#include "game.h"

static char	*attack(player_t *player)
{
	char	*str = NULL;

	my_putstr(1, "\nattack: ");
	while ((str = get_input(0)) != NULL && (letter_in_map(str[0]) == 0 ||
						nbr_in_map(str[1]) == 0 ||
						my_strlen(str) > 2)) {
		my_putstr(1, "wrong position\n");
		my_putstr(1, "attack: ");
	}
	if (str == NULL) {
		return (MALLOC_ERROR);
	}
	encrypt(player->enemy_pid, str);
	return (str);
}

int	wait_turn(player_t *player)
{
	char	*pos = NULL;

	my_putstr(1, "\nwaiting for enemy's attack...\n");
	pause();
	pos = catch_signal();
	if (pos == NULL)
		return (ERROR);
	kill(player->enemy_pid,
	check_in_map(pos, player->map));
	return (SUCCESS);
}

int	attack_turn(player_t *player)
{
	char	*pos = NULL;

	pos = attack(player);
	if (pos == MALLOC_ERROR)
		return (ERROR);
	my_putstr(1, pos);
	my_putstr(1, ": ");
	mark_map_enemy(pos, player->enemy_map);
	return (SUCCESS);
}
