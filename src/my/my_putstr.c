/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** display a string
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(int out, char const *str)
{
	write(out, str, my_strlen(str));
}
