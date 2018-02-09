/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check enter pos player
*/

#include <unistd.h>
#include <stdlib.h>
#include "play_game.h"
#include "tools_navy.h"
#include "get_next_line.h"
#include "init_game.h"
#include "my.h"

char	*check_target(void)
{
	char *stock = NULL;

	set_italic_text();
	stock = get_next_line(0);
	unset_italic_text();
	if (stock == MALLOC_ERROR)
		return (MALLOC_ERROR);
	return (stock);
}

int	target_pos(void)
{
	char *gnl = NULL;

	my_putstr(1, "attack: ");
	gnl = check_target();
	if (gnl == MALLOC_ERROR)
		return (ERROR);
	else if (letter_in_map(gnl[0]) == 0 || nbr_in_map(gnl[1]) == 0)
		return (ERROR);
	return (SUCCESS);
}
