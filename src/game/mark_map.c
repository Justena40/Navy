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
	if (rec_sig == 0)
		en_map[pos[0] - 'A'][(pos[1] - '0') - 1] = 'o';
	else
		en_map[pos[0] - 'A'][(pos[1] - '0') - 1] = 'x';
}
