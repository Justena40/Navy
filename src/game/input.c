/*
** EPITECH PROJECT, 2018
** navy
** File description:
** get inputs
*/

#include <stdlib.h>
#include "tools_navy.h"
#include "get_next_line.h"

char	*get_input(int fd)
{
	char	*str = NULL;

	set_italic_text();
	str = get_next_line(fd);
	unset_italic_text();
	return (str);
}
