/*
** EPITECH PROJECT, 2018
** navy
** File description:
** init_map and put ships on map
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "tools_navy.h"
#include "init_game.h"

static void	init_first_line_map(void)
{
	my_putstr(1, " |A B C D E F G H\n");
	my_putstr(1, "-+---------------\n");
}

static void	put_point_in_map(char *line)
{
	int	count = 0;

	while (count < MAP_HEIGHT) {
		line[count] = '.';
		count += 1;
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
	int	count2 = 0;
	int	count = 0;
	char	nbr = count + '1';

	init_first_line_map();
	while (count < MAP_WIDTH) {
		write(1, &nbr, 1);
		write(1, "|", 1);
		while (count2 < MAP_WIDTH) {
			write(1, &map[count][count2], 1);
			write(1, " ", 1);
			count2++;
		}
		my_putstr(1, "\n");
		count2 = 0;
		count++;
		nbr = count + '1';
	}
}
