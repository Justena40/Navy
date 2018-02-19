/*
** EPITECH PROJECT, 2018
** navy
** File description:
** game functions
*/

#ifndef GAME_H_
#define GAME_H_

#include <stdbool.h>
#include "player.h"

/************ INIT ************/

int	game(int argc, char **argv);
int	host_loop(player_t *host);
int	player_loop(player_t *player);
int	connect_player(player_t *player);
int	player_connection(player_t *host);
char	**open_file_and_do_map(char *str);
int	letter_in_map(char c);
int	nbr_in_map(char c);
int	great_length(char c1, char c2, char nbr);
char	**init_map(void);
void	display_map(char **map);
int	put_ship(char **map, char *pos_ship);

/************ GAME ************/

int	wait_turn(player_t *player);
int	attack_turn(player_t *player);
char	*get_input(int fd);
void	mark_map_enemy(char *pos, char **en_map);
void	encrypt(int pid_enn, char *pos_shoot);
void	display_miss_or_hit(char *pos);
char	*catch_signal(void);
int	check_in_map(char *pos, char **map);
bool	check_win(char **map);

#endif /*GAME_H_*/
