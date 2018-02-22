/*
** EPITECH PROJECT, 2018
** navy
** File description:
** mark map
*/

#include "signal_handler.h"
#include "game.h"
#include "my.h"

void	mark_map_enemy(char *pos, char **en_map)
{
	if (rec_sig == 0 &&
	en_map[(pos[1] - '0') - 1][pos[0] - 'A'] == 'x') {
		my_putstr(1, "missed\n");
		en_map[(pos[1] - '0') - 1][pos[0] - 'A'] = 'x';
	} else if (rec_sig == 0) {
		my_putstr(1, "missed\n");
		en_map[(pos[1] - '0') - 1][pos[0] - 'A'] = 'o';
	} else {
		my_putstr(1, "hit\n");
		en_map[(pos[1] - '0') - 1][pos[0] - 'A'] = 'x';
	}
}
