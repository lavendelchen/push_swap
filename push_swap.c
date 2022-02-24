/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:59:41 by shaas             #+#    #+#             */
/*   Updated: 2022/02/24 17:17:41 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list			stack_a;
	t_list			stack_b;
	unsigned int	numnum;

	stack_b.head = NULL;
	stack_b.tail = NULL;
	parse_input(argc, argv, &stack_a);
	numnum = assign_ranks(&stack_a);
	//print_stacks(&stack_a, &stack_b);
	if (is_sorted(&stack_a) == false)
		the_algorithm(&stack_a, &stack_b, numnum);
	/*
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	print_stacks(&stack_a, &stack_b);
	reverse_rotate_a(&stack_a);
	print_stacks(&stack_a, &stack_b);
	reverse_rotate_b(&stack_b);
	print_stacks(&stack_a, &stack_b);
	reverse_rotate_ab(&stack_a, &stack_b);
	print_stacks(&stack_a, &stack_b);
	rotate_a(&stack_a);
	print_stacks(&stack_a, &stack_b);
	rotate_b(&stack_b);
	print_stacks(&stack_a, &stack_b);
	rotate_ab(&stack_a, &stack_b);
	print_stacks(&stack_a, &stack_b);
	swap_a(&stack_a);
	print_stacks(&stack_a, &stack_b);
	swap_b(&stack_b);
	print_stacks(&stack_a, &stack_b);
	swap_ab(&stack_a, &stack_b);
	print_stacks(&stack_a, &stack_b);
	*/
	//do_stuff_lol(&stack_a, &stack_b);
	exit_cleanly(&stack_a, &stack_b, EXIT_SUCCESS);
}

/*
printf("\e[96mhere?\e[0m\n");
*/
