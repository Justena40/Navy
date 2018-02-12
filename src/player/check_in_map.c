/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check in map
*/

#include <signal.h>

int	check_in_map(char *pos, char **map, int pid_enn)
{
	printf("map[%d][%d] => %c\n", pos[0] - 48, pos[1] - 48, map[pos[0] - 48][pos[1] - 48]);
	if (map[pos[0] - 48][pos[1] - 48] == '.') {
		map[pos[0] - 48][pos[1] - 48] = 'o';
		kill(pid_enn, SIGUSR1);
		printf("envoie si c'est miss un USR1\n");
		return (1);
	} else {
		map[pos[0] - 48][pos[1] - 48] = 'x';
		kill(pid_enn, SIGUSR2);
		printf("envoie si c'est shoot un USR2\n");
	}
	return (0);
}
