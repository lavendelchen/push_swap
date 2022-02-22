/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:59:41 by shaas             #+#    #+#             */
/*   Updated: 2022/02/22 18:03:41 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;

	stack_b.head = NULL;
	stack_b.tail = NULL;
	parse_input(argc, argv, &stack_a);
	//do_stuff_lol(&stack_a, &stack_b);
}

/*
printf("\e[96mhere?\e[0m\n");
*/
