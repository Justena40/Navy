/*
** EPITECH PROJECT, 2018
** navy
** File description:
** player1_turn
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "tools_navy.h"
#include "play_game.h"
#include "init_game.h"
#include "my.h"

void	init_start_turn(char **my_map, char **map_enemy)
{
	my_putstr(1, "my positions:\n");
	display_map(my_map);
	my_putstr(1, "\nenemy's positions:\n");
	display_map(map_enemy);
}

static int	check_status(char *pos, char **map)
{
	if (rec_sig == 0) {
		map[pos[0] - 'A'][pos[1] - 48] = 'x';
		return (1);
	}
	else {
		map[pos[0] - 'A'][pos[1] - 48] = 'o';
		return (0);
	}
}

void	begin_game_player1(char **my_map, int pid_enn)
{
	char **map_enemy = NULL;
	char	*pos = NULL;
	int win = 0;

	map_enemy = init_map();
	init_start_turn(my_map, map_enemy);
	init_sig();
	while (win != 1 || win != 2) {
		pos = target_pos(pid_enn);
		if (pos == NULL) {
			return;
		}
		pause();// pause en att que l autre rep
		//j2 envoi un signal pour hit ou missed -> decrypt();
		//if pour miss ou hit
		//complete la map ennemi -> function
//		my_putstr(1, "waiting for enemy's attack...\n");
//		pause();  //pause j2 joue;
		if (check_status(pos, my_map) == 1)
			kill(pid_enn, SIGUSR1);
		else
			kill(pid_enn, SIGUSR2);
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
		//recevoir signal de son jeu (gnl j2)
		//decrypte et dire si hit ou miss
	}
}
