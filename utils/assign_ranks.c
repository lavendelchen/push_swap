/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:48:00 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 18:15:45 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*find_biggest_number_in_stack(t_list *stack)
{
	t_node	*iter;
	t_node	*biggest;

	iter = stack->head;
	biggest = stack->head;
	while (iter != NULL)
	{
		if (iter->num >= biggest->num)
			biggest = iter;
		iter = iter->next;
	}
	return (biggest);
}

static void	init_values(t_node **iter, t_node **smallest, \
t_list *stack_a, t_node *biggest)
{
	*iter = stack_a->head;
	*smallest = biggest;
}

static unsigned int	actually_assign_ranks(t_list *stack_a, unsigned int rank, \
									t_node *smaller, t_node *biggest)
{
	t_node		*iter;
	t_node		*smallest;
	bool		done_sth;

	while (true)
	{
		init_values(&iter, &smallest, stack_a, biggest);
		done_sth = false;
		while (iter != NULL)
		{
			if (iter->num <= smallest->num && \
			(smaller == NULL || iter->num > smaller->num))
			{
				smallest = iter;
				done_sth = true;
			}
			iter = iter->next;
		}
		if (done_sth == false)
			break ;
		smallest->rank = rank;
		smaller = smallest;
		rank++;
	}
	return (smallest->rank + 1);
}

unsigned int	assign_ranks(t_list *stack_a)
{
	unsigned int	rank;
	t_node			*smaller;
	t_node			*biggest;

	rank = 0;
	smaller = NULL;
	biggest = find_biggest_number_in_stack(stack_a);
	return (actually_assign_ranks(stack_a, rank, smaller, biggest));
}
