/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:41:09 by shaas             #+#    #+#             */
/*   Updated: 2022/03/01 21:56:18 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_path(t_node *starter)
{
	t_node	*iter;

	iter = starter;
	while (iter != NULL)
	{
		iter->path = iter->potential_path;
		iter = iter->potential_path;
	}
}

t_node	*find_next_bigger_number(t_node *nbr)
{
	t_node	*bigger;
	t_node	*iter;

	iter = nbr;
	bigger = NULL;
	while (bigger == NULL && iter != NULL)
	{
		if (nbr->rank < iter->rank)
			bigger = iter;
		iter = iter->next;
	}
	return (bigger);
}

t_node	*find_longest_sequence(t_list *stack_a)
{
	t_node	*starter;
	t_node	*iter;
	t_node	*bigger;

	starter = stack_a->head;
	iter = starter;
	while (iter != NULL)
	{
		bigger = find_next_bigger_number(iter);
		iter->potential_path = bigger;
		iter = iter->potential_path;
	}
	copy_path(starter);
	print_subsequence(stack_a); //
	return (starter);
}

void	init_stacks(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	t_node		*iter;
	t_node		*next;
	t_node		*subs;
	unsigned int	i;

	i = 0;
	iter = stack_a->head;
	subs = find_longest_sequence(stack_a);
	while (i < numnum)
	{
		next = iter->next;
		if (iter == subs)
		{
			rotate_a(stack_a);
			subs = subs->path;
		}
		else
			push_b(stack_a, stack_b);
		iter = next;
		i++;
	}
}

void	logical_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	init_stacks(stack_a, stack_b, numnum);
}