/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:36:02 by jeykim            #+#    #+#             */
/*   Updated: 2022/10/06 17:54:34 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# define LEN 8
# define SLP_TIME 300

# include "ft_printf.h"
# include "signal.h"
# include "stdlib.h"

typedef struct elem{
	int					count;
	char				letter;
	pid_t				pid;
	struct sigaction	sa;
}	t_elem;

typedef struct celem{
	char				*str;
	int					idx;
	pid_t				pid;
}	t_celem;

int	ft_atoi(const char *str);

#endif