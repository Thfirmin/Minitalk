/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                          :+:     :+:            */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:54:54 by thfirmin          #+#    #+#             */
/*   Updated: 2022/08/23 02:11:57 by Thinotsuki   ###     ###.br              */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_return(int signum);

int	ft_isalldigit(char	*str);

int	main(int argc, char *argv[])
{
	pid_t	n_pid;

	signal(SIGUSR1, ft_return);
	if ((argc != 3) || (!ft_isalldigit(argv[1])))
	{
		ft_printf("\e[38;5;196mERROR: \e[mincorrect argument!\e[38;5;87m\n");
		ft_printf("NOTE: \e[mCorrect Argument format [./client <PID> <STR>]\n");
		exit(EXIT_FAILURE);
	}
	n_pid = ft_atoi(argv[1]);
	kill(n_pid, SIGUSR1);
	usleep (300);
	exit(EXIT_FAILURE);
}

int	ft_isalldigit(char	*str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

void	ft_return(int signum)
{
	(void)signum;
	ft_printf ("Message sucefully from sended!\n");
	exit(EXIT_SUCCESS);
}

