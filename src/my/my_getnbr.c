/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** second chance
*/

#include "my.h"

int	my_getnbr(char const *str)
{
	int	count = 0;
	int	minus = 1;
	int	nb = 0;

	while (str[count] == '-' || str[count] == '+') {
		if (str[count] == '-') {
			minus = minus * (-1);
		}
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9') {
		nb = nb * 10 + (str[count] - '0');
		count++;
	}
	return (nb * minus);
}
