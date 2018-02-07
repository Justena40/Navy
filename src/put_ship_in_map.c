/*
** EPITECH PROJECT, 2018
** navy
** File description:
** put ship in map and verify if it's possible
*/

#include <unistd.h>
#include "my.h"
#include "tools_navy.h"
#include "init_game.h"

static void	swap_case(char *pos_ship)
{
	char	save_charac;

	if (pos_ship[2] < pos_ship[5]) {
		save_charac = pos_ship[2];
		pos_ship[2] = pos_ship[5];
		pos_ship[5] = save_charac;
	}
}

static int	draw_ship_height(char **map, char *pos)
{
	int	count_pos = -1;
	int	count_map = 0;

	printf("pos %s\n", pos);
	while (pos[3] + count_pos < pos[6]) {
		map[(pos[3] - '0') + count_pos][pos[2] - 'A'] = pos[0];
		count_map += 2;
		count_pos++;
		printf("pos 2 - A  =  %d\n", pos[2] - 'A');
	}
	return (SUCCESS);
}

static int	draw_ship_hor(char **map, char *pos)
{
	int	count = 0;

	while (pos[2] + count < pos[5]) {
		map[pos[3] - '0'][(pos[2] - 'A') + count] = pos[0];
		count++;
	}
	return (SUCCESS);
}

int	put_ship(char **map, char *pos_ship)
{
	swap_case(pos_ship);
	if (pos_ship[2] != pos_ship[5]) {
		draw_ship_hor(map, pos_ship);
	} else
		draw_ship_height(map, pos_ship);
	return (SUCCESS);
}
