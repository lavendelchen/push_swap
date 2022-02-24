/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:18:20 by shaas             #+#    #+#             */
/*   Updated: 2022/02/24 23:03:29 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RAND_MAX 10
#include "push_swap.h"


void	the_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	unsigned int	rank;

	rank = 0;
	(void)numnum;
	while (stack_a->head != NULL)
	{
		if (stack_a->head->rank == rank)
		{
			push_b(stack_a, stack_b);
			rank++;
		}
		else
			rotate_a(stack_a);
	}
	while (stack_b->head != NULL)
		push_a(stack_a, stack_b);
}

void	the_algorithm2(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	struct timeval	tv;
	int				r;

	while (is_sorted(stack_a, numnum) == false)
	{
		gettimeofday(&tv, NULL);
		srand(tv.tv_usec);
		r = rand() % 11;
		switch (r)
		{
			case 0:
				push_a(stack_a, stack_b);
				break;
			case 1:
				push_b(stack_a, stack_b);
				break;
			case 2:
				swap_a(stack_a);
				break;
			case 3:
				swap_b(stack_b);
				break;
			case 4:
				swap_ab(stack_a, stack_b);
				break;
			case 5:
				rotate_a(stack_a);
				break;
			case 6:
				rotate_b(stack_b);
				break;
			case 7:
				rotate_ab(stack_a, stack_b);
				break;
			case 8:
				reverse_rotate_a(stack_a);
				break;
			case 9:
				reverse_rotate_b(stack_b);
				break;
			case 10:
				reverse_rotate_ab(stack_a, stack_b);
				break;
		}
	}
}