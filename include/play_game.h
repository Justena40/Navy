/*
** EPITECH PROJECT, 2018
** navy
** File description:
** play_game
*/

#ifndef PLAY_GAME_H_
#define PLAY_GAME_H_

void	begin_game_player1(char **my_map);
void	begin_game_player2(char **my_map);
int	target_pos(void);
void	init_start_turn(char **my_map, char **map_enemy);

#endif /* PLAY_GAME_H_ */
