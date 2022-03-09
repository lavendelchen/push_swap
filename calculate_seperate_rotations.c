/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_seperate_rotations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:18:41 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 17:57:45 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*the way this works is, we try to find the next biggest number in stack_a
to the number we want to push from stack b. 
but, if the number is bigger than all the numbers on a, we can't find anything.
so, while iterating through the list, we also find the smallest number. and 
if our number is the biggest number, the smallest is "equal" to next biggest.*/
static t_node	*find_bottom(t_list *stack_a, t_node *node)
{
	t_node	*iter;
	t_node	*bottom;
	t_node	*smallest;

	iter = stack_a->head;
	bottom = NULL;
	smallest = stack_a->head;
	while (iter != NULL)
	{
		if ((bottom == NULL && iter->rank > node->rank) || \
			(iter->rank > node->rank && iter->rank < bottom->rank))
			bottom = iter;
		if (iter->rank < smallest->rank)
			smallest = iter;
		iter = iter->next;
	}
	if (bottom == NULL)
		bottom = smallest;
	return (bottom);
}

unsigned int	calculate_rotate(t_node *node, t_list *stack)
{
	t_node			*iter;
	unsigned int	rotate;

	iter = node;
	rotate = 0;
	while (iter != stack->head)
	{
		iter = iter->prev;
		rotate++;
	}
	return (rotate);
}

unsigned int	calculate_reverse_rotate(t_node *node, t_list *stack)
{
	t_node			*iter;
	unsigned int	reverse_rotate;

	iter = node;
	reverse_rotate = 0;
	while (iter != NULL && iter != stack->head)
	{
		iter = iter->next;
		reverse_rotate++;
	}
	return (reverse_rotate);
}

void	calculate_seperate_rotations(\
t_node *node, t_sort *sort, t_list *stack_a, t_list *stack_b)
{
	t_node	*bottom;

	bottom = find_bottom(stack_a, node);
	sort->rb = calculate_rotate(node, stack_b);
	sort->rrb = calculate_reverse_rotate(node, stack_b);
	sort->ra = calculate_rotate(bottom, stack_a);
	sort->rra = calculate_reverse_rotate(bottom, stack_a);
}
