/*
** EPITECH PROJECT, 2018
** navy
** File description:
** encryption and decod of signal
*/

#include <unistd.h>
#include <stdlib.h>
#include "signal_handler.h"
#include "tools_navy.h"
#include "encrypt.h"
#include "my.h"

static void	init_struc(encrypt_t arr_crypt[16])
{
	arr_crypt[0] = (encrypt_t) {'1', "000"};
	arr_crypt[1] = (encrypt_t) {'2', "001"};
	arr_crypt[2] = (encrypt_t) {'3', "010"};
	arr_crypt[3] = (encrypt_t) {'4', "011"};
	arr_crypt[4] = (encrypt_t) {'5', "100"};
	arr_crypt[5] = (encrypt_t) {'6', "101"};
	arr_crypt[6] = (encrypt_t) {'7', "110"};
	arr_crypt[7] = (encrypt_t) {'8', "111"};
	arr_crypt[8] = (encrypt_t) {'A', "000"};
	arr_crypt[9] = (encrypt_t) {'B', "001"};
	arr_crypt[10] = (encrypt_t) {'C', "010"};
	arr_crypt[11] = (encrypt_t) {'D', "011"};
	arr_crypt[12] = (encrypt_t) {'E', "100"};
	arr_crypt[13] = (encrypt_t) {'F', "101"};
	arr_crypt[14] = (encrypt_t) {'G', "110"};
	arr_crypt[15] = (encrypt_t) {'H', "111"};
}

static void	init_pos(char *x, char *y, char *buffer)
{
	y[0] = buffer[0];
	y[1] = buffer[1];
	y[2] = buffer[2];
	y[3] = '\0';
	x[0] = buffer[3];
	x[1] = buffer[4];
	x[2] = buffer[5];
	x[3] = '\0';
}

void	encrypt(int pid_enn, char *pos_shoot)
{
	encrypt_t	arr_crypt[16];
	int		count = 0;

	init_struc(arr_crypt);
	while (pos_shoot[0] != arr_crypt[count].charac) {
		count++;
	}
	send_signal(arr_crypt[count].sig, pid_enn);
	count = 0;
	while (pos_shoot[1] != arr_crypt[count].charac)
		count++;
	send_signal(arr_crypt[count].sig, pid_enn);
}

char	*decrypt(char *buffer)
{
	encrypt_t	arr_crypt[16];
	int		count = 0;
	char		x[4];
	char		y[4];
	char		*pos;

	pos = malloc(sizeof(char) * 3);
	if (pos == NULL)
		return (NULL);
	init_struc(arr_crypt);
	init_pos(x, y, buffer);
	while (my_strcmp(x, arr_crypt[count].sig) != 0)
		count++;
	pos[0] = arr_crypt[count].charac - 1;
	count = 0;
	while (my_strcmp(y, arr_crypt[count].sig) != 0)
		count++;
	pos[1] = arr_crypt[count].charac - 1;
	pos[2] = '\0';
	return (pos);
}

char	*catch_signal(void)
{
	char	buffer[6];
	char	*ret = NULL;
	int	count = 0;

	while (count < 5) {
		buffer[count] = rec_sig + '0';
		pause();
		count++;
	}
	buffer[count] = rec_sig + '0';
	ret = decrypt(buffer);
	return (ret);
}
