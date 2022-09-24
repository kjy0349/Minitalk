/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:17:01 by seohyuki          #+#    #+#             */
/*   Updated: 2022/09/24 16:34:41 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	str = argv[2];
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
			usleep(80);
			sub_idx++;
		}
		idx++;
	}
}
