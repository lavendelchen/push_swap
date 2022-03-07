/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:59:41 by shaas             #+#    #+#             */
/*   Updated: 2022/03/06 22:55:27 by shaas            ###   ########.fr       */
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
	logical_algorithm(&stack_a, &stack_b, numnum);
	exit_cleanly(&stack_a, &stack_b, EXIT_SUCCESS);
}

/*
("\e[96mhere?\e[0m\n");
*/
