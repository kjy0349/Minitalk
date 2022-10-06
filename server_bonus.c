/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:51:54 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/06 18:27:27 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_elem	g_info;

void	print_bit(int signum)
{
	usleep(SLP_TIME);
	if (signum == SIGUSR2)
		g_info.letter += (1 << g_info.count);
	g_info.count++;
	if (g_info.count == LEN)
	{
		g_info.count = 0;
		if (g_info.letter == 0)
		{
			kill(g_info.pid, SIGUSR2);
			g_info.pid = 0;
			return ;
		}
		else
		{
			ft_printf("%c", g_info.letter);
			g_info.letter = 0;
		}
	}
	kill(g_info.pid, SIGUSR1);
}

void	get_signal(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (g_info.pid == 0)
		g_info.pid = info->si_pid;
	else if (g_info.pid != info->si_pid)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	print_bit(signum);
}

int	main(int argc, char	*argv[])
{
	pid_t				pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	g_info.sa.sa_sigaction = (void *)get_signal;
	g_info.sa.sa_flags = SA_SIGINFO;
	sigemptyset(&g_info.sa.sa_mask);
	pid = getpid();
	g_info.count = 0;
	g_info.letter = 0;
	g_info.pid = 0;
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &g_info.sa, NULL);
	sigaction(SIGUSR2, &g_info.sa, NULL);
	while (1)
		pause();
	return (0);
}
