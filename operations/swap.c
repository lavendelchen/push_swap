/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:26:52 by shaas             #+#    #+#             */
/*   Updated: 2022/03/06 23:31:18 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements
*/

void	swap_a(t_list *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	first = stack_a->head;
	second = stack_a->head->next;
	ps_lstrm_head(stack_a);
	ps_lstrm_head(stack_a);
	ps_lstadd_head(stack_a, first);
	ps_lstadd_head(stack_a, second);
	ft_putendl_fd("sa", 1);
	//print_ranks(stack_a, NULL);
}

void	swap_b(t_list *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (stack_b->head == NULL || stack_b->head->next == NULL)
		return ;
	first = stack_b->head;
	second = stack_b->head->next;
	ps_lstrm_head(stack_b);
	ps_lstrm_head(stack_b);
	ps_lstadd_head(stack_b, first);
	ps_lstadd_head(stack_b, second);
	ft_putendl_fd("sb", 1);
	//print_ranks(NULL, stack_b);
}

void	swap_ab(t_list *stack_a, t_list *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (stack_a->head != NULL && stack_a->head->next != NULL)
	{
		first = stack_a->head;
		second = stack_a->head->next;
		ps_lstrm_head(stack_a);
		ps_lstrm_head(stack_a);
		ps_lstadd_head(stack_a, first);
		ps_lstadd_head(stack_a, second);
	}
	if (stack_b->head != NULL && stack_b->head->next != NULL)
	{
		first = stack_b->head;
		second = stack_b->head->next;
		ps_lstrm_head(stack_b);
		ps_lstrm_head(stack_b);
		ps_lstadd_head(stack_b, first);
		ps_lstadd_head(stack_b, second);
	}
	ft_putendl_fd("ss", 1);
	//print_ranks(stack_a, stack_b);
}
