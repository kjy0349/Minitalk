/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:17:01 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/06 18:27:10 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check(int signum)
{
	if (signum != SIGUSR1)
		exit(0);
}

int	send_str(char *str, int pid)
{
	int		idx;
	int		sub_idx;
	int		flag;
	char	elem;

	flag = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		flag = 1;
		sub_idx = 0;
		elem = str[idx];
		while (sub_idx < LEN)
		{
			usleep(SLP_TIME);
			if ((elem & (1 << sub_idx)) != 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			sub_idx++;
			pause();
		}
		idx++;
	}
	return (flag);
}

void	send_zero(int pid)
{
	int	sub_idx;

	sub_idx = 0;
	while (sub_idx < LEN)
	{
		usleep(SLP_TIME);
		kill(pid, SIGUSR1);
		sub_idx++;
		pause();
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;
	int		flag;
	int		sub_idx;

	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	if (pid < 100)
		exit(0);
	str = argv[2];
	signal(SIGUSR1, check);
	signal(SIGUSR2, check);
	flag = send_str(str, pid);
	sub_idx = 0;
	if (flag)
		send_zero(pid);
	return (0);
}
