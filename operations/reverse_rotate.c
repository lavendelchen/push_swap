/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:26:46 by shaas             #+#    #+#             */
/*   Updated: 2022/03/06 00:02:28 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_list *stack_a, t_list *stack_b)
{
	t_node	*rotate;

	(void)stack_b;
	rotate = stack_a->tail;
	ps_lstrm_tail(stack_a);
	ps_lstadd_head(stack_a, rotate);
	ft_putendl_fd("rra", 1);
	//print_ranks(stack_a, NULL);
}

void	reverse_rotate_b(t_list *stack_a, t_list *stack_b)
{
	t_node	*rotate;

	(void)stack_a;
	rotate = stack_b->tail;
	ps_lstrm_tail(stack_b);
	ps_lstadd_head(stack_b, rotate);
	ft_putendl_fd("rrb", 1);
	//print_ranks(NULL, stack_b);
}

void	reverse_rotate_ab(t_list *stack_a, t_list *stack_b)
{
	t_node	*rotate;

	rotate = stack_a->tail;
	ps_lstrm_tail(stack_a);
	ps_lstadd_head(stack_a, rotate);
	rotate = stack_b->tail;
	ps_lstrm_tail(stack_b);
	ps_lstadd_head(stack_b, rotate);
	ft_putendl_fd("rrr", 1);
	//print_ranks(stack_a, stack_b);
}