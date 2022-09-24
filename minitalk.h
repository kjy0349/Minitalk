/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:36:02 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/24 16:03:37 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define LEN 8

# include "ft_printf.h"
# include "signal.h"
# include "stdlib.h"

typedef struct elem{
	int	count;
	int	letter;
}	t_elem;

int	ft_atoi(const char *str);

#endif