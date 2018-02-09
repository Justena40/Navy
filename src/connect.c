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
#include "my.h"

static void	my_handler(int signal, siginfo_t *sig, void *context)
{
	if (signal == 10)
		printf("salut\n");
	else if (signal == 12)
		printf("coucou\n");
}

void	connect_other(int pid, int *state, char *str)
{
	//envoi signal pour demarrer le jeu et rendre rep pour j1
	//print success
	struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_sigaction = &my_handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == 0 ||
	sigaction(SIGUSR2, &sig, NULL) == 0) {
		kill(my_getnbr(str), SIGUSR1);
		my_putstr(1, "successfully connected\n");
	}
	pause();
}

void	connect_host(int pid, int *state)
{
	struct sigaction	sig;

	//pause  pour attendre la connection de j2
	//qd j2 connecté (on recoit le signal et on prend son pid)
	my_putstr(1, "\nwaiting for enemy connection...");
	pause();
	sigemptyset(&sig.sa_mask);
	sig.sa_sigaction = &my_handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == 0 ||
	sigaction(SIGUSR2, &sig, NULL) == 0) {
		my_putstr(1, "\nennemy connected\n");
		*state = 1;
	}
}
