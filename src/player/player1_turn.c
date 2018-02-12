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

void	start_turn(char **my_map, char **map_enemy)
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

void	display_miss_or_hit(char *pos)
{
	my_putstr(1, pos);
	my_putstr(1, ": ");
	if (rec_sig == 0)
		my_putstr(1, "missed\n");
	else
		my_putstr(1, "hit\n");
}

void	begin_game_player1(char **my_map, int pid_enn)
{
	char **map_enemy = NULL;
	char	*pos = NULL;
	int win = 0;

	map_enemy = init_map();
	init_sig();
	while (win != 1 || win != 2) {
		pos = target_pos(pid_enn);
		if (pos == NULL)
			return;
		pause();
		display_miss_or_hit(pos);
		//change_map_enn(pos, map_ennemy);
		kill(pid_enn, SIGUSR1);
		my_putstr(1, "waiting for enemy's attack...\n");
		pause();
		start_turn(my_map, map_enemy);
		pos = catch_signal(pid_enn);
		if (pos == MALLOC_ERROR)
			return;
		check_in_map(pos, my_map, pid_enn);
		kill(pid_enn, SIGUSR1);
		pause();
	}
}

/*
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
*/
