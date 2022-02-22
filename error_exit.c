/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:32:42 by shaas             #+#    #+#             */
/*   Updated: 2022/02/22 18:02:51 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_cleanly(t_list *stack_a, t_list *stack_b, int is_failure)
{
	t_node	*buf;

	if (stack_a != NULL)
	{
		buf = stack_a->head;
		while (buf != NULL)
		{
			free(buf);
			buf = buf->next;
		}
	}
	if (stack_b != NULL)
	{
		buf = stack_b->head;
		while (buf != NULL)
		{
			free(buf);
			buf = buf->next;
		}
	}
	exit(is_failure);
}

void	error_exit(t_list *stack_a, t_list *stack_b)
{
	ft_putendl_fd("Error\n", 2);
	exit_cleanly(stack_a, stack_b, EXIT_FAILURE);
}
