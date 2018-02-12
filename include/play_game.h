/*
** EPITECH PROJECT, 2018
** navy
** File description:
** play_game
*/

#ifndef PLAY_GAME_H_
#define PLAY_GAME_H_

void	begin_game_player1(char **my_map, int pid_enn);
void	begin_game_player2(char **my_map, int pid_enn);
char	*target_pos(int pid_enn);
void	encrypt(int pid_enn, char *pos_shoot);
void	start_turn(char **my_map, char **map_enemy);
void	display_miss_or_hit(char *pos);
char	*catch_signal(int pid_enn);
void	init_sig();
int	check_in_map(char *pos, char **map, int pid_enn);

#endif /* PLAY_GAME_H_ */
