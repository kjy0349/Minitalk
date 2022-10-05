/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:36:02 by jeykim            #+#    #+#             */
/*   Updated: 2022/10/05 19:17:14 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define LEN 8
# define SLP_TIME 500

# include "ft_printf.h"
# include "signal.h"
# include "stdlib.h"

typedef struct elem{
	int		count;
	int		letter;
	pid_t	pid;
}	t_elem;

typedef struct celem{
	char				*str;
	struct sigaction	sa;
	int					idx;
	pid_t				pid;
}	t_celem;

int	ft_atoi(const char *str);

#endif