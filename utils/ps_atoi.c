/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:51:43 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 18:07:13 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ps_whitespace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static void	check_sign(char **str, int *sign)
{
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
} //let's hope this works

int	ps_atoi(char *str, t_list *stack_a)
{
	long long	i;
	int			sign;

	i = 0;
	sign = 1;
	while (ps_whitespace(*str) == 1)
		str++;
	check_sign(&str, &sign);
	if (*str < '0' || *str > '9')
		error_exit(stack_a, NULL);
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
