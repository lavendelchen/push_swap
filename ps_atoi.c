/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:51:43 by shaas             #+#    #+#             */
/*   Updated: 2022/02/16 18:06:47 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_whitespace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ps_atoi(const char *str, t_list *stack_a)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (ps_whitespace(*str) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ps_whitespace(*str) == 0 && *str != '\0')
	{
		if (*str < '0' || *str > '9')
			error_exit(stack_a, NULL);
		i = i * 10;
		i = i + (*str - '0');
		str++;
	}
	i = i * sign;
	if (i < INT_MIN || i > INT_MAX)
		error_exit(stack_a, NULL);
	return ((int)i);
}
