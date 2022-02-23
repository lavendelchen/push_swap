/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:26:49 by shaas             #+#    #+#             */
/*   Updated: 2022/02/23 03:53:05 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list *stack_a)
{
	t_node	*rotate;

	rotate = stack_a->head;
	ps_lstrm_head(stack_a);
	ps_lstadd_tail(stack_a, rotate);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_list *stack_b)
{
	t_node	*rotate;

	rotate = stack_b->head;
	ps_lstrm_head(stack_b);
	ps_lstadd_tail(stack_b, rotate);
	ft_putendl_fd("rb", 1);
}

void	rotate_ab(t_list *stack_a, t_list *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putendl_fd("rr", 1);
}