/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** get length of string
*/

int	my_strlen(char const *str)
{
	int	count = 0;

	while (str[count] != '\0')
		count++;
	return (count);
}
