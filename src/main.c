/*
** EPITECH PROJECT, 2018
** navy
** File description:
** main for navy
*/

#include "game.h"
#include "tools_navy.h"
#include "my.h"

static void	display_usage(void)
{
	my_putstr(2, "USAGE\n");
	my_putstr(2, "		./navy ");
	my_putstr(2, "[first_player_pid] ");
	my_putstr(2, "navy_positions\n\n");
	my_putstr(2, "DESCRIPTION\n");
	my_putstr(2, "\tfirst_player_pid");
	my_putstr(2, "   only for the 2nd player.");
	my_putstr(2, " pid of the first player.\n");
	my_putstr(2, "\tnavy_positions");
	my_putstr(2, "     file representing the positions ");
	my_putstr(2, "of the ships.\n");
}

static void	display_winner(int res)
{
	if (res == 0)
		my_putstr(1, "I won\n");
	else
		my_putstr(1, "Enemy won\n");
}

int	main(int argc, char **argv)
{
	int	res = 0;

	if (argc == 1 || argc > 3)
		return (ERROR);
	else if (my_strcmp(argv[1], "-h") == 0) {
		display_usage();
		return (ERROR);
	}
	if ((res = game(argc, argv)) == ERROR)
		return (ERROR);
	display_winner(res);
	return (res);
}
