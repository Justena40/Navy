/*
** EPITECH PROJECT, 2018
** navy
** File description:
** open file and do map with ships
*/

#include <stdlib.h>
#include <fcntl.h>
#include "init_game.h"
#include "tools_navy.h"
#include "my.h"
#include "get_next_line.h"

static int	look_one_ship(char *pos_ship)
{
	int	res1 = 0;
	int	res2 = 0;

	if (my_strlen(pos_ship) != 7 || nbr_in_map(pos_ship[0]) == 0 ||
	letter_in_map(pos_ship[2]) == 0 || nbr_in_map(pos_ship[3]) == 0 ||
	letter_in_map(pos_ship[5]) == 0 || nbr_in_map(pos_ship[6]) == 0)
		return (ERROR);
	res1 = great_length(pos_ship[2], pos_ship[5], pos_ship[0]);
	res2 = great_length(pos_ship[3], pos_ship[6], pos_ship[0]);
	if (res1 == ERROR || res2 == ERROR ||
	(res1 == CONTINUE && res2 == CONTINUE) ||
	(res1 == SUCCESS && res2 == SUCCESS))
		return (ERROR);
	return (SUCCESS);
}

static int	check_pos_ships(char *pos_ship, char **map)
{
	int	res = 0;

	res = look_one_ship(pos_ship);
	if (res == ERROR)
		return (ERROR);
	res = put_ship(map, pos_ship);
	if (res == ERROR)
		return (ERROR);
	return (SUCCESS);
}

char	**open_file_and_do_map(char *str)
{
	int	count = 0;
	int	fd = 0;
	char	**map = NULL;
	char	**pos_ship = malloc(sizeof(char *) * (NBR_SHIPS + 1));

	if (pos_ship == NULL)
		return (MALLOC_ERROR);
	map = init_map();
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (MALLOC_ERROR);
	while (count < NBR_SHIPS) {
		pos_ship[count] = get_next_line(fd);
		if (pos_ship[count] == NULL ||
		check_pos_ships(pos_ship[count], map) == ERROR)
			return (MALLOC_ERROR);
		count++;
	}
	display_map(map);
	return (map);
}
