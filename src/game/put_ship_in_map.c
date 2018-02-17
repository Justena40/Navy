/*
** EPITECH PROJECT, 2018
** navy
** File description:
** put ship in map and verify if it's possible
*/

#include <unistd.h>
#include "my.h"
#include "tools_navy.h"
#include "game.h"

static int	swap_case(char *pos_ship)
{
	return (pos_ship[2] > pos_ship[5]);
}

static int	draw_ship_height(char **map, char *pos)
{
	int	count_pos = -1;

	while (pos[3] + count_pos < pos[6]) {
		if (map[(pos[3] - '0') + count_pos][pos[2] - 'A'] != '.')
			return (ERROR);
		map[(pos[3] - '0') + count_pos][pos[2] - 'A'] = pos[0];
		count_pos++;
	}
	return (SUCCESS);
}

static int	draw_ship_hor(char **map, char *pos)
{
	int	count = 0;

	while (pos[2] + count <= pos[5]) {
		if (map[pos[3] - '0' - 1][(pos[2] - 'A') + count] != '.')
			return (ERROR);
		map[pos[3] - '0' - 1][(pos[2] - 'A') + count] = pos[0];
		count++;
	}
	return (SUCCESS);
}

int	put_ship(char **map, char *pos_ship)
{
	if (swap_case(pos_ship) == 1)
		return (ERROR);
	if (pos_ship[2] != pos_ship[5]) {
		if (draw_ship_hor(map, pos_ship) == ERROR)
			return (ERROR);
	} else {
		if (draw_ship_height(map, pos_ship) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
