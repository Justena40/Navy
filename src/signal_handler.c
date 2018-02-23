/*
** EPITECH PROJECT, 2018
** navy
** File description:
** signal functions
*/

#include <stdlib.h>
#include <unistd.h>
#include "signal_handler.h"

int	rec_sig = -1;

void pid_handler(__attribute__((unused))int signal,
		siginfo_t *siginfo,
		__attribute__((unused))void *context)
{
	rec_sig = siginfo->si_pid;
}

void sig_handle(int signal,
		__attribute__((unused))siginfo_t *siginfo,
		__attribute__((unused))void *context)
{
	if (signal == SIGUSR1)
		rec_sig = 0;
	else if (signal == SIGUSR2)
		rec_sig = 1;
}

void	send_signal(char *sig, int pid_enn)
{
	int		send_sig = 0;

	while (sig[send_sig] != '\0') {
		if (sig[send_sig] == '0')
			kill(pid_enn, SIGUSR1);
		else
			kill(pid_enn, SIGUSR2);
		usleep(1000);
		send_sig++;
	}
}

bool	init_signal(void (*sig_handler)(int signal,
					siginfo_t *siginfo, void *context))
{
	struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sig, NULL) == -1 ||
	sigaction(SIGUSR2, &sig, NULL) == -1)
		return (false);
	return (true);
}
