/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:18:20 by shaas             #+#    #+#             */
/*   Updated: 2022/02/24 16:55:36 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	the_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	unsigned int	rank;

	rank = 0;
	numnum = 5;
	while (stack_a->head != NULL)
	{
		if (stack_a->head->rank == rank)
		{
			push_b(stack_a, stack_b);
			rank++;
		}
		else
			rotate_a(stack_a);
	}
	while (stack_b->head != NULL)
		push_a(stack_a, stack_b);
}
