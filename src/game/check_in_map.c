/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check in map
*/

#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include "my.h"

bool	check_win(char **map)
{
	int	count_x = 0;
	int	count_y = 0;
	int	count_cross = 0;

	while (map[count_x] != NULL) {
		while (map[count_x][count_y] != '\0') {
			if (map[count_x][count_y] == 'x')
				count_cross++;
			count_y++;
		}
		count_y = 0;
		count_x++;
	}
	if (count_cross == 14)
		return (true);
	return (false);
}

static char	*swap_arr_pos(char *pos)
{
	char	tmp;

	tmp = pos[0] + 1;
	pos[0] = pos[1] + ('A' - '0');
	pos[1] = tmp;
	return (pos);
}

int	check_in_map(char *pos, char **map)
{
	if (map[pos[0] - 48][pos[1] - 48] == '.' ||
	    map[pos[0] - 48][pos[1] - 48] == 'o') {
		map[pos[0] - 48][pos[1] - 48] = 'o';
		pos = swap_arr_pos(pos);
		my_putstr(1, pos);
		my_putstr(1, ": missed\n");
		return (10);
	}
	else if (map[pos[0] - 48][pos[1] - 48] == 'x') {
		my_putstr(1, pos);
		my_putstr(1, ": missed\n");
		return (10);
	}
	map[pos[0] - 48][pos[1] - 48] = 'x';
	pos = swap_arr_pos(pos);
	my_putstr(1, pos);
	my_putstr(1, ": hit\n");
	return (12);
}
