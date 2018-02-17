/*
** EPITECH PROJECT, 2018
** navy
** File description:
** signal header
*/

#ifndef SIGNAL_HANDLER_H_
#define SIGNAL_HANDLER_H_

#include <signal.h>
#include <stdbool.h>

extern int rec_sig;

void	pid_handler(int signal, siginfo_t *siginfo, void *context);
void	sig_handle(int signal, siginfo_t *siginfo, void *context);
void	send_signal(char *message, int pid);
bool	init_signal(void (*sig_handler)(int signal,
					siginfo_t *siginfo, void *context));

#endif /*SIGNAL_HANDLER_H_*/
