/*
** EPITECH PROJECT, 2018
** navy
** File description:
** player2 turn
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "tools_navy.h"
#include "play_game.h"
#include "init_game.h"
#include "my.h"

static int check_status(char *pos, char **map)
{
	if (rec_sig == 0)
	{
		map[pos[0] - 'A'][pos[1] - 48] = 'x';
		return (1);
	}
	else
	{
		map[pos[0] - 'A'][pos[1] - 48] = 'o';
		return (0);
	}
}

void	begin_game_player2(char **my_map, int pid_enn)
{
	char **map_enemy =  NULL;
	char	*pos = NULL;
	int ret = 0;
	int win = 0;

	map_enemy = init_map();
	init_start_turn(my_map, map_enemy);
	init_sig();
	while (win != 1  || win != 2) {
		my_putstr(1, "waiting for enemy's attack...\n");
		pause();
		pos = catch_signal(pid_enn);
		if (pos == NULL)
			return;
		if (check_in_map(pos, my_map))
			kill(pid_enn, SIGUSR1);
		else
			kill(pid_enn, SIGUSR2);
		pause();
		pos = target_pos(pid_enn);
		if (pos == NULL) {
			return;
		}
		if (check_status(pos, my_map) == 1) {
			kill(pid_enn, SIGUSR1);
		}
		else
			kill(pid_enn, SIGUSR2);
		//pause();
		//envoi signal criptee vers j1
		//pause en att que l autre rep
		//j1 envoi in signal pour hit ou missed
		//complete la map enemy
	}
}
