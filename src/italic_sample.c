/*
** EPITECH PROJECT, 2018
** navy
** File description:
** set and unset italic text
*/

#include "my.h"

void	set_italic_text(void)
{
	my_putstr(1, "\x1b[3m");
}

void	unset_italic_text(void)
{
	my_putstr(1, "\x1b[0m");
}
