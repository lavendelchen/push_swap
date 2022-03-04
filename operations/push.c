/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:26:43 by shaas             #+#    #+#             */
/*   Updated: 2022/03/04 19:48:41 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_list *stack_a, t_list *stack_b)
{
	t_node	*push;

	push = stack_a->head;
	ps_lstrm_head(stack_a);
	ps_lstadd_head(stack_b, push);
	ft_putendl_fd("pb", 1);
	//print_ranks(stack_a, stack_b);
}

void	push_a(t_list *stack_a, t_list *stack_b)
{
	t_node	*push;

	push = stack_b->head;
	ps_lstrm_head(stack_b);
	ps_lstadd_head(stack_a, push);
	ft_putendl_fd("pa", 1);
	//print_ranks(stack_a, stack_b);
}
