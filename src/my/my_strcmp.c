/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** compare two strings
*/

#include "my.h"

int	my_strcmp(char const *str1, char const *str2)
{
	int	count = 0;

	if (my_strlen(str1) != my_strlen(str2)) {
		return (my_strlen(str1) - my_strlen(str2));
	}
	while (str1[count] != '\0' && str2[count] != '\0') {
		if (str1[count] != str2[count]) {
			return (str1[count] - str2[count]);
		}
		count++;
	}
	return (0);
}
