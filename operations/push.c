/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:26:43 by shaas             #+#    #+#             */
/*   Updated: 2022/02/16 17:32:49 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list *stack_a, t_list *stack_b)
{
	t_node *push; //whhat if stack_b doesn't contain anything yet? need to handle. \
	also what if there's nothing in a lol
	
	push = stack_a->start;
	if (stack_b->start == NULL) // this is wrong so far
		stack_b->end = push;
	else
	{
		push->next = stack_b->start;
		stack_b->start->prev = push;
	}
	stack_a->start = stack_a->start->next;
	stack_a->start->prev = NULL;
	stack_b->start = push;
}

void	push_a(t_list *stack_a, t_list *stack_b)
{
	
}

//special cases to handle: only one element, list empty, list becomes empty ?????