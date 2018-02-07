/*
** EPITECH PROJECT, 2018
** navy
** File description:
** init_map and put ships on map
*/

#include <stdlib.h>
#include "my.h"
#include "tools_navy.h"
#include "init_game.h"

static void	put_point_in_map(char *line)
{
	int	count = 0;

	while (count < MAP_HEIGHT) {
		line[count] = '.';
		line[count + 1] = ' ';
		count += 2;
	}
	line[count] = '\0';
}

char	**init_map(void)
{
	char	**map = malloc(sizeof(char *) * (MAP_WIDTH + 1));
	int	count = 0;

	if (map == NULL)
		return (MALLOC_ERROR);
	while (count < MAP_WIDTH) {
		map[count] = malloc(sizeof(char) * (MAP_HEIGHT + 1));
		if (map[count] == NULL)
			return (MALLOC_ERROR);
		put_point_in_map(map[count]);
		count++;
	}
	map[count] = NULL;
	return (map);
}

void	display_map(char **map)
{
	int	count = 0;

	while (count < MAP_WIDTH) {
		my_putstr(1, map[count]);
		my_putstr(1, "\n");
		count++;
	}
}
