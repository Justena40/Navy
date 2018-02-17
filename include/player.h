/*
** EPITECH PROJECT, 2018
** navy
** File description:
** player structure
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <sys/types.h>
#include <unistd.h>

typedef struct player
{
	pid_t	pid;
	pid_t	enemy_pid;
	char	**map;
	char	**enemy_map;
}player_t;

#endif /*!PLAYER_H_*/
