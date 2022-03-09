/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_to_a_efficiently.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:21:47 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 17:26:53 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_sort_for_node(t_node *node, t_sort *sort, t_list *stack_a, t_list *stack_b)
{
	t_shortest_path	shortest_path;

	calculate_seperate_rotations(node, sort, stack_a, stack_b);
	find_shortest_combination(sort, &shortest_path);
	set_sort_to_combination(&shortest_path, sort);
}

static t_node	*calculate_sort(t_list *stack_a, t_list *stack_b)
{
	t_node	*iter;
	t_node	*shortest;

	shortest = stack_b->head;
	iter = stack_b->head;
	while (iter != NULL)
	{
		calculate_sort_for_node(iter, &iter->sort, stack_a, stack_b);
		if (iter->sort.sum < shortest->sort.sum)
			shortest = iter;
		iter = iter->next;
	}
	return (shortest);
}

void	push_all_to_a_efficiently(t_list *stack_a, t_list *stack_b)
{
	t_node	*sort;

	while (stack_b->head != NULL)
	{
		sort = calculate_sort(stack_a, stack_b);
		do_operation_number_of_times(rotate_ab, sort->sort.rr, stack_a, stack_b);
		do_operation_number_of_times(reverse_rotate_ab, sort->sort.rrr, stack_a, stack_b);
		do_operation_number_of_times(rotate_b, sort->sort.rb, stack_a, stack_b);
		do_operation_number_of_times(reverse_rotate_b, sort->sort.rrb, stack_a, stack_b);
		do_operation_number_of_times(rotate_a, sort->sort.ra, stack_a, stack_b);
		do_operation_number_of_times(reverse_rotate_a, sort->sort.rra, stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}
