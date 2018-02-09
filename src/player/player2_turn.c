/*
** EPITECH PROJECT, 2018
** navy
** File description:
** player2 turn
*/

#include <unistd.h>
#include <stdlib.h>
#include "tools_navy.h"
#include "play_game.h"
#include "init_game.h"
#include "my.h"

void	begin_game_player2(char **my_map)
{
	char **map_enemy =  NULL;
	int ret = 0;
	int win = 0;

	map_enemy = init_map();
	init_start_turn(my_map, map_enemy);
	while (win != 1  || win != 2) {
		//pause pdt que j1
		//recevoir signal de son jeu (gnl j1)
		//decrypte et dire miss ou hit
		//renvoyer signal pour j1
		//pause att j1 finisse
		ret = target_pos();
		while (ret == ERROR) {
			my_putstr(1, "wrong position\n");
			ret = target_pos();
		}
		//envoi signal criptee vers j1
		//pause en att que l autre rep
		//j1 envoi in signal pour hit ou missed
		//complete la map enemy
		my_putstr(1, "waiting for enemy's attack...\n");
	}
}
