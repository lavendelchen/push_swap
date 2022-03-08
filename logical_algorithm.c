/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:18:45 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 00:23:17 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
what to do: 
- new files for big file
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

void	do_operation_number_of_times(void (*function)(t_list *, t_list *), unsigned int times, t_list *stack_a, t_list *stack_b)
{
	unsigned int	i;

	i = 0;
	while (i < times)
	{
		function(stack_a, stack_b);
		i++;
	}
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

void	rotate_a_to_correct_order(t_list *stack_a, t_list *stack_b)
{
	t_node			*smallest;
	unsigned int	end_ra;
	unsigned int	end_rra;

	smallest = stack_a->head;
	while (smallest->rank != 0)
		smallest = smallest->next;
	end_ra = calculate_rotate(smallest, stack_a);
	end_rra = calculate_reverse_rotate(smallest, stack_a);
	if (end_ra <= end_rra)
		do_operation_number_of_times(rotate_a, end_ra, stack_a, stack_b);
	else
		do_operation_number_of_times(reverse_rotate_a, end_rra, stack_a, stack_b);
}

void	big_sort(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	init_l_i_s(stack_a, stack_b, numnum);
	push_all_to_a_efficiently(stack_a, stack_b);
	rotate_a_to_correct_order(stack_a, stack_b);
}

void	small_sort(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	unsigned int	pushb;
	unsigned int	first;
	unsigned int	second;
	unsigned int	third;

	pushb = numnum - 3;
	while (pushb > 0)
	{
		push_b(stack_a, stack_b);
		pushb--;
	}
	first = stack_a->head->rank;
	second = stack_a->head->next->rank;
	third = stack_a->tail->rank;
	if (first < third && third < second)
		swap_a(stack_a);
	else if (second < first && first < third)
		swap_a(stack_a);
	else if (third < second && second < first)
		swap_a(stack_a);
	push_all_to_a_efficiently(stack_a, stack_b);
	rotate_a_to_correct_order(stack_a, stack_b);
}

void	logical_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	if (numnum == 2)
		swap_a(stack_a);
	else if (numnum <= 9) //need to see what is more efficient, which numbers to add
		small_sort(stack_a, stack_b, numnum);
	else
		big_sort(stack_a, stack_b, numnum);
}

//python3 pyviz.py `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`