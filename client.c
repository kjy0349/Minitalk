/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:17:01 by seohyuki          #+#    #+#             */
/*   Updated: 2022/10/06 18:27:13 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_str(char *str, int pid)
{
	int		idx;
	char	elem;
	int		sub_idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		sub_idx = 0;
		elem = str[idx];
		while (sub_idx < LEN)
		{
			if ((elem & (1 << sub_idx)) != 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(SLP_TIME);
			sub_idx++;
		}
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_str(str, pid);
}
