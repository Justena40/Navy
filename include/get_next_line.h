/*
** EPITECH PROJECT, 2018
** get_next_line.h
** File description:
** get next line
*/

#ifndef	GET_NEXT_LINE_H_
#define	GET_NEXT_LINE_H_

#ifndef	READ_SIZE
#define	READ_SIZE	(100000)
#endif		/*READ_SIZE*/

#define	MALLOC_ERROR	NULL
#define	FAIL		-1
#define	CONTINUE	1
#define	SUCCESS		0

char	*get_next_line(int fd);

#endif		/*GET_NEXT_LINE_H_*/
