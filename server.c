/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:51:54 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/24 16:23:33 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_elem	g_info;

void	get_signal(int signum);

int	main(int argc, char	*argv[])
{
	struct sigaction	sa;
	pid_t				pid;
	sigset_t			set;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	sa.sa_handler = get_signal;
	sigemptyset(&set);
	pid = getpid();
	g_info.count = 0;
	g_info.letter = 0;
	ft_printf("%d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}

void	get_signal(int signum)
{
	if (signum == SIGUSR1)
		g_info.count++;
	if (signum == SIGUSR2)
	{
		g_info.letter += 1 << g_info.count;
		g_info.count++;
	}
	if (g_info.count == LEN)
	{
		ft_printf("%c", g_info.letter);
		g_info.count = 0;
		g_info.letter = 0;
	}
}
