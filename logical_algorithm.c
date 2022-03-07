/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:18:45 by shaas             #+#    #+#             */
/*   Updated: 2022/03/06 23:35:44 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
what to do: 
- make logical algorithm function prettier
- macro for operations & combination types
- norm in general
- make small algos
- check more testers
- check subject and eval sheet
- checker? nahh idc
*/

void	calculate_sort_for_node(t_node *node, t_sort *sort, t_list *stack_a, t_list *stack_b)
{
	t_shortest_path	shortest_path;

	calculate_seperate_rotations(node, sort, stack_a, stack_b);
	find_shortest_combination(sort, &shortest_path);
	set_sort_to_combination(&shortest_path, sort);
}

t_node	*calculate_sort(t_list *stack_a, t_list *stack_b)
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

void	do_operation_number_of_times(int operation, unsigned int times, t_list *stack_a, t_list *stack_b)
{
	void			(*function)(t_list *, t_list *);
	unsigned int	i;

	i = 0;
	if (operation == 0)
		function = &rotate_ab;
	else if (operation == 1)
		function = &reverse_rotate_ab;
	else if (operation == 2)
		function = &rotate_b;
	else if (operation == 3)
		function = &reverse_rotate_b;
	else if (operation == 4)
		function = &rotate_a;
	else if (operation == 5)
		function = &reverse_rotate_a;
	while (i < times)
	{
		function(stack_a, stack_b);
		i++;
	}
}

void	logical_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	t_node			*sort;
	unsigned int	end_ra;
	unsigned int	end_rra;

	init_stacks(stack_a, stack_b, numnum);
	while (stack_b->head != NULL)
	{
		sort = calculate_sort(stack_a, stack_b);
		do_operation_number_of_times(0, sort->sort.rr, stack_a, stack_b);
		do_operation_number_of_times(1, sort->sort.rrr, stack_a, stack_b);
		do_operation_number_of_times(2, sort->sort.rb, stack_a, stack_b);
		do_operation_number_of_times(3, sort->sort.rrb, stack_a, stack_b);
		do_operation_number_of_times(4, sort->sort.ra, stack_a, stack_b);
		do_operation_number_of_times(5, sort->sort.rra, stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	sort = stack_a->head;
	while (sort->rank != 0)
		sort = sort->next;
	end_ra = calculate_rotate(sort, stack_a);
	end_rra = calculate_reverse_rotate(sort, stack_a);
	if (end_ra <= end_rra)
		do_operation_number_of_times(4, end_ra, stack_a, stack_b);
	else
		do_operation_number_of_times(5, end_rra, stack_a, stack_b);
}

//python3 pyviz.py `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`