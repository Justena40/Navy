/*
** EPITECH PROJECT, 2018
** navy
** File description:
** include for before the begin game
*/

#ifndef	INIT_GAME_H_
#define INIT_GAME_H_

int	game(char **argv);
char	**open_file_and_do_map(char *str);
int	letter_in_map(char c);
int	nbr_in_map(char c);
int	great_length(char c1, char c2, char nbr);
char	**init_map(void);
void	display_map(char **map);
int	put_ship(char **map, char *pos_ship);

#endif		/*INIT_GAME_H_*/
