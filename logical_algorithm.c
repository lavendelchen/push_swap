/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:18:45 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 17:39:03 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
what to do: 
- new files for big file
- macro for operations & combination types
- norm in general
- check more testers
- check subject and eval sheet
- checker? nahh idc
*/

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

void	logical_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	if (numnum == 2)
	{
		swap_a(stack_a);
		return ;
	}
	else if (numnum <= 9)
		init_three_sort(stack_a, stack_b, numnum);
	else
		init_l_i_s(stack_a, stack_b, numnum);
	push_all_to_a_efficiently(stack_a, stack_b);
	rotate_a_to_correct_order(stack_a, stack_b);
}

//python3 pyviz.py `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`