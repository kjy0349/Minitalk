/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:17:01 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/05 19:19:14 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_celem g_cinfo;

void	check(int signum, siginfo_t *info)
{
	(void)info;
	if (signum != SIGUSR1)
		exit(0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		idx;
	int		sub_idx;
	char	*str;
	char	elem;

	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	idx = 0;
	g_cinfo.str = argv[2];
	g_cinfo.sa.sa_sigaction = (void *)check;
	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	idx = 0;
	str = argv[2];
	sigaction(SIGUSR1, &g_cinfo.sa, NULL);
	sigaction(SIGUSR2, &g_cinfo.sa, NULL);
	while (str[idx] != '\0')
	{
		sub_idx = 0;
		elem = str[idx];
		while (sub_idx < LEN)
		{
			usleep(SLP_TIME);
			if ((elem & (1 << sub_idx)) != 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			pause();
			sub_idx++;
		}
		idx++;
	}
	sub_idx = 0;
	while (sub_idx < LEN)
	{
		usleep(SLP_TIME);
		kill(pid, SIGUSR1);
		pause();
		sub_idx++;
	}
}
