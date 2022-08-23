/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                          :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:55:15 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/23 02:03:06 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	usrhandler(int signum, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction usr_h;

	usr_h.sa_sigaction = &usrhandler;
	usr_h.sa_flags = SA_SIGINFO | SA_RESTART;

	sigaction (SIGUSR1, &usr_h, NULL);
	ft_printf("\e[38;5;112;1mStarted Process!\e[m\n");
	ft_printf ("PID: \e[38;5;112;1m%d\e[m\n", getpid());
	while (1)
		pause();
	return (1);
}

void	usrhandler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	ft_printf("SIGNAL FROM %d RECEIVED!\n", signum);
	kill(info->si_pid, SIGUSR1);
}
