/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:51:54 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/05 19:21:38 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_elem	g_info;

void	get_signal(int signum, siginfo_t *info, void *context)
{
	usleep(SLP_TIME);
	(void)context;
	if (g_info.pid == 0)
		g_info.pid = info->si_pid;
	if (g_info.pid != info->si_pid)
		kill(info->si_pid, SIGUSR2);
	else
	{
		usleep(SLP_TIME);
		if (signum == SIGUSR1)
		{
			g_info.count++;
			kill(g_info.pid, SIGUSR1);
		}
		if (signum == SIGUSR2)
		{
			g_info.letter += 1 << g_info.count;
			g_info.count++;
			kill(g_info.pid, SIGUSR1);
		}
		if (g_info.count == LEN)
		{
			g_info.count = 0;
			if (g_info.letter == 0)
			{
				ft_printf("\n");
				g_info.pid = 0;
				kill(g_info.pid, SIGUSR2);
				g_info.letter = 0;
				pause();
			}
			else
			{
				ft_printf("%c\n", g_info.letter);
				g_info.letter = 0;
			}
		}
	}
}

int	main(int argc, char	*argv[])
{
	struct sigaction	sa;
	pid_t				pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	sa.sa_sigaction = (void *)get_signal;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	g_info.count = 0;
	g_info.letter = 0;
	g_info.pid = 0;
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
