/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:41:09 by shaas             #+#    #+#             */
/*   Updated: 2022/03/04 22:09:17 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_bottom(t_list *stack_a, t_node *node)
{
	t_node	*iter;
	t_node	*bottom;

	iter = stack_a->head;
	bottom = NULL;
	while (iter != NULL)
	{
		if (bottom == NULL && iter->rank > node->rank) 
			bottom = iter;
		else if (iter->rank > node->rank && iter->rank < bottom->rank)
		{
			bottom = iter;
			break ;
		}
		iter = iter->next;
	}
	if (bottom == NULL)
	{
		iter = stack_a->head;
		bottom = stack_a->head;
		while (iter != NULL)
		{
			if (iter->rank < bottom->rank)
			{
				bottom = iter;
				break ;
			}
			iter = iter->next;
		}
	}
	return (bottom);
}

//to do: shorten bottom function! maybe different approach to handle big number that doesn't have bottom
//also: we have handled rb & rrb, finding bottom makes ra & rra possible. then we can start to add up. look at paper.

void	calculate_sort_for_node(t_node *node, t_list *stack_a, t_list *stack_b)
{
	t_node	*iter;
	t_node	*bottom;

	node->sort.rb = 0;
	node->sort.rrb = 0;
	node->sort.ra = 0;
	node->sort.rra = 0;
	node->sort.rr = 0;
	node->sort.rrr = 0;
	iter = node;
	while (iter != stack_b->head)
	{
		iter = iter->prev;
		node->sort.rb++;
	}
	iter = node;
	while (iter != NULL && iter != stack_b->head)
	{
		iter = iter->next;
		node->sort.rrb++;
	}
	iter = stack_a->head;
	printf("\e[96mhere?\e[0m\n");
	bottom = find_bottom(stack_a, node);
	while (iter != NULL)
	{
		if (bottom == NULL && iter->rank > node->rank) 
			bottom = iter;
		else if (iter->rank > node->rank && iter->rank < bottom->rank)
		{
			bottom = iter;
			break ;
		}
		iter = iter->next;
	}
	if (bottom == NULL)
	{
		iter = stack_a->head;
		bottom = stack_a->head;
		while (iter != NULL)
		{
			if (iter->rank < bottom->rank)
			{
				bottom = iter;
				break ;
			}
			iter = iter->next;
		}
	}
	printf("num: %4d, rb_num: %4d, rrb_num: %4d, bottom: %4d\n", node->rank, node->sort.rb, node->sort.rrb, bottom->rank);
}

t_node	*calculate_sort(t_list *stack_a, t_list *stack_b) // have to change it every time
{
	t_node	*iter;

	iter = stack_b->head;
	while (iter != NULL)
	{
		calculate_sort_for_node(iter, stack_a, stack_b);
		iter = iter->next;
	}
	return (iter);
	//then see which one's the shortest sum
}

void	logical_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	t_node	*sort;

	init_stacks(stack_a, stack_b, numnum);
	print_ranks(stack_a, stack_b);
	sort = calculate_sort(stack_a, stack_b);
}