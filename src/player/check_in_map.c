/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check in map
*/

int	check_in_map(char *pos, char **map)
{
	if (map[pos[0] - 48][pos[1] - 48] != '.') {
		map[pos[0] - 48][pos[1] - 48] = 'o';
		return (1);
	}
	map[pos[0] - 48][pos[1] - 48] = 'x';
	return (0);
}
