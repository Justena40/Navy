/*
** EPITECH PROJECT, 2018
** navy
** File description:
** player1_turn
*/

#include <unistd.h>
#include <stdlib.h>
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

void	begin_game_player1(char **my_map)
{
	char **map_enemy = NULL;
	int ret = 0;
	int win = 0;

	map_enemy = init_map();
	init_start_turn(my_map, map_enemy);
	while (win != 1 || win != 2) {
		ret = target_pos();
		while (ret == ERROR) {
			my_putstr(1, "wrong position\n");
			ret = target_pos();
		}
		//envoi le signal criptee vers j2 -> encryp();
		pause(); // pause en att que l autre rep
		//j2 envoi un signal pour hit ou missed -> decrypt();
		//if pour miss ou hit
		//complete la map ennemi -> function
		my_putstr(1, "waiting for enemy's attack...\n");
		pause();  //pause j2 joue;
		//recevoir signal de son jeu (gnl j2)
		//decrypte et dire si hit ou miss
	}
}
