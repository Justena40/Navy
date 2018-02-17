/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check in map
*/

#include <signal.h>
#include "my.h"

int	check_in_map(char *pos, char **map)
{
	char	tmp;

	if (map[pos[0] - 48][pos[1] - 48] == '.') {
		map[pos[0] - 48][pos[1] - 48] = 'o';
		tmp = pos[0] + 1;
		pos[0] = pos[1] + ('A' - '0');
		pos[1] = tmp;
		my_putstr(1, pos);
		my_putstr(1, ": missed\n");
		return (10);
	}
	map[pos[0] - 48][pos[1] - 48] = 'x';
	tmp = pos[0] + 1;
	pos[0] = pos[1] + ('A' - '0');
	pos[1] = tmp;
	my_putstr(1, pos);
	my_putstr(1, ": hit\n");
	return (12);
}
