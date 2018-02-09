/*
** EPITECH PROJECT, 2017
** my_put_nbrdec
** File description:
** putnbr in unsigned int
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_put_nbrdec(int nb)
{
	int c = 0;
	int t = 1;
	int cop = nb;

	while (nb >= 10) {
		nb = nb / 10;
		t = t * 10;
	}
	while (t != 0) {
		c = cop / t;
		cop = cop - c * t;
		t = t / 10;
		my_putchar(c + 48);
	}
	return (0);
}
