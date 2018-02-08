/*
** EPITECH PROJECT, 2018
** getnextline
** File description:
** main function
*/

#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "my.h"

int	my_str(char const *str)
{
	int index = 0;

	if (str == NULL)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*my_realloc(char *rec, char *stock)
{
	char *tmp = malloc(sizeof(char) * ((my_str(rec) + my_str(stock)) + 2));
	int index = 0;
	int index2 = 0;

	if (tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	while (rec[index] != '\0') {
		tmp[index] = rec[index];
		index += 1;
	}
	tmp[index] = '\0';
	free(rec);
	rec = NULL;
	while (stock[index2] != '\0')
		tmp[index++] = stock[index2++];
	tmp[index] = '\0';
	tmp[index + 1] = '\0';
	stock = NULL;
	return (tmp);
}

int	check_caract(int size, char *buffer, char **rec)
{
	char *stock = NULL;
	static char *save = NULL;
	int index = 0;
	int index2 = 0;
	int index3 = 0;
	int check = 0;

	if (size == 0 && (save == NULL || save[0] == '\0'))
		return (-2);
	stock = malloc(sizeof(char) * (size + my_str(save) + 1));
	if (stock == NULL)
		return (84);
	stock[0] = '\0';
	if (save != NULL) {
		stock = my_realloc(stock, save);
		free(save);
		save = NULL;
	}
	index2 = my_str(stock);
	stock = my_realloc(stock, buffer);
	index = 0;
	index2 = 0;
	index3 = 0;
	save = malloc(sizeof(char) * my_str(&stock[index]));
	if (save == NULL)
		return (84);
	save[0] = '\0';
	while (stock[index] != '\0') {
		if (stock[index] == '\n') {
			check = 1;
			index3 = index;
			index += 1;
			while (stock[index] != '\0')
				save[index2++] = stock[index++];
			save[index2] = '\0';
			stock[index3] = '\0';
		}
		index += 1;
	}
	*rec = my_realloc(*rec, stock);
	if (save[0] == '\0') {
		free(save);
		save = NULL;
	}
	if (check == 1)
		return (-1);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	char buffer[READ_SIZE + 1];
	char *rec = malloc(sizeof(char) *(READ_SIZE + 1));
	int size = 1;
	int bool = 0;

	if (rec == NULL)
		return (NULL);
	rec[0] = '\0';
	buffer[size] = '\0';
	while (size > 0) {
		size = read(fd, buffer, READ_SIZE);
		buffer[size] = '\0';
		bool = check_caract(size, buffer, &rec);
		if (bool == -2)
			return (NULL);
		if (bool == -1)
			return (rec);
	}
	return (NULL);
}
