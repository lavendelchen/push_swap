/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:26:43 by shaas             #+#    #+#             */
/*   Updated: 2022/02/22 18:02:51 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list *stack_a, t_list *stack_b)
{
	t_node *push; //whhat if stack_b doesn't contain anything yet? need to handle. \
	also what if there's nothing in a lol
	
	if (stack_a->head == NULL)
		return ;
	push = stack_a->head;
	if (stack_b->head == NULL) // this is wrong so far
	{
		ps_lstinit(stack_b, push);
		ps_lstrmhead(stack_a);
	}
	else
	{
		push->next = stack_b->head;
		stack_b->head->prev = push;
	}
	stack_a->head = stack_a->head->next;
	stack_a->head->prev = NULL;
	stack_b->head = push;
}

void	push_a(t_list *stack_a, t_list *stack_b)
{
	
}

//special cases to handle: only one element, list empty, list becomes empty ?????