/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check if ships is on great position
*/

#include <stdlib.h>
#include "tools_navy.h"

int	letter_in_map(char c)
{
	return (c >= 'A' && c <= 'H');
}

int	nbr_in_map(char c)
{
	return (c > '1' && c < '9');
}

// c1 premier charac à comparer avec le 2eme charac voir si ils sont egaux au length

int	great_length(char c1, char c2, char nbr)
{
	if (c2 - c1 + 48 == '0')
		return (CONTINUE);
	else if (c2 - c1 + 48 == nbr - 1)
		return (SUCCESS);
	return (ERROR);
}
