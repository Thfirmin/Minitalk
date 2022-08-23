/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                          :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:55:15 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/23 01:14:22 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_usrhandler(int signum);

int	main(void)
{
	pid_t	n_pid;
	struct sigaction usr_h;
	usr_h.sa_handler = ft_usrhandler;
	usr_h.sa_flags = SA_RESTART;

	n_pid = getpid();
	sigaction (SIGUSR1, &usr_h, NULL);
	ft_printf("\e[38;5;112;1mStarted Process!\e[m\n");
	ft_printf ("PID: \e[38;5;112;1m%d\e[m\n", n_pid);
	while (1)
		pause();
}

void	ft_usrhandler(int signum)
{
	ft_printf("SIGNAL FROM %d RECEIVED!\n", signum);
}
