/*
** EPITECH PROJECT, 2018
** navy
** File description:
** connect each other
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "tools_navy.h"
#include "my.h"

int	rec_sig = -1;

static void	my_handler(int signal, siginfo_t *siginfo,
			void *context)
{
	if (signal == 10) {
		rec_sig = siginfo->si_pid;
	}
	else if (signal == 12)
		rec_sig = siginfo->si_pid;
}

void	connect_other(char *str)
{
	kill(my_getnbr(str), SIGUSR1);
	my_putstr(1, "\nsuccessfully connected\n");
}


int	connect_host(int pid)
{
	struct sigaction	sig;

	my_putstr(1, "\nwaiting for enemy connection...");
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &my_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pause();
	my_putstr(1, "\nennemy connected\n");
	return (rec_sig);
}
