/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:26:49 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 17:30:02 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list *stack_a, t_list *stack_b)
{
	t_node	*rotate;

	(void)stack_b;
	rotate = stack_a->head;
	ps_lstrm_head(stack_a);
	ps_lstadd_tail(stack_a, rotate);
	ft_putendl_fd("ra", 1);
	//print_ranks(stack_a, stack_b);
}

void	rotate_b(t_list *stack_a, t_list *stack_b)
{
	t_node	*rotate;

	(void)stack_a;
	rotate = stack_b->head;
	ps_lstrm_head(stack_b);
	ps_lstadd_tail(stack_b, rotate);
	ft_putendl_fd("rb", 1);
	//print_ranks(stack_a, stack_b);
}

void	rotate_ab(t_list *stack_a, t_list *stack_b)
{
	t_node	*rotate;

	rotate = stack_a->head;
	ps_lstrm_head(stack_a);
	ps_lstadd_tail(stack_a, rotate);
	rotate = stack_b->head;
	ps_lstrm_head(stack_b);
	ps_lstadd_tail(stack_b, rotate);
	ft_putendl_fd("rr", 1);
	//print_ranks(stack_a, stack_b);
}