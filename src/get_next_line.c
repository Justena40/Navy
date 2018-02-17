/*
** EPITECH PROJECT, 2018
** get_next_line1.c
** File description:
** gnl
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	my_strlen(char const *str, int pos)
{
	int	count = pos;

	while (str != NULL && (str[count] != '\n' && str[count] != '\0'))
		count++;
	return (count);
}

static char	*realloc_ret(char *buffer, char *ret, int *count_buf)
{
	char	*tmp = malloc(sizeof(char) *
			(my_strlen(buffer, *count_buf)
			+ my_strlen(ret, 0) + 1));
	int	count = 0;

	if (tmp == NULL) {
		free(ret);
		return (ERROR_NULL);
	}
	if (ret != NULL) {
		while (ret[count] != '\0') {
			tmp[count] = ret[count];
			count++;
		}
	}
	while (buffer[*count_buf] != '\0' && buffer[*count_buf] != '\n')
		tmp[count++] = buffer[(*count_buf)++];
	tmp[count] = '\0';
	free(ret);
	return (tmp);
}

static int	read_file(int fd, char *buffer,
			int *count_buf, int *current_file)
{
	*count_buf = 0;
	if ((*current_file = read(fd, buffer, READ_SIZE)) < 0)
		return (FAIL);
	buffer[*current_file] = '\0';
	return (*current_file);
}

static int	begin_read(char *buffer, int *current_file, int fd, char **ret)
{
	int		res = 0;
	static int	count_buf = 0;

	if (buffer[count_buf] == '\0' || count_buf != READ_SIZE ||
	count_buf != 0) {
		*ret = realloc_ret(buffer, *ret, &count_buf);
		if (buffer[count_buf] == '\n')
			return (++count_buf, CONTINUE);
	}
	while ((res = read_file(fd, buffer, &count_buf, current_file)) > 0) {
		if ((*ret = realloc_ret(buffer, *ret,
					&count_buf)) == ERROR_NULL)
			return (FAIL);
		if (buffer[count_buf] == '\n')
			return (++count_buf, SUCCESS);
	}
	if (res == -1)
		return (FAIL);
	return (SUCCESS);
}

char	*get_next_line(int fd)
{
	static char	buffer[READ_SIZE + 1] = { '\0' };
	int		current_file = 0;
	char		*ret = NULL;
	int		status = 0;

	if ((status = begin_read(buffer, &current_file, fd, &ret)) == FAIL)
		return (ERROR_NULL);
	else if (status == CONTINUE)
		return (ret);
	if (current_file == 0) {
		if (ret[0] == '\0') {
			free(ret);
			return (ERROR_NULL);
		}
	}
	else if (current_file == -1) {
		if (ret == NULL)
			return (ERROR_NULL);
	}
	return (ret);
}
