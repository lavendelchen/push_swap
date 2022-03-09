/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_three_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:19:10 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 17:19:40 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_three_sort(t_list *stack_a, t_list *stack_b, unsigned int numnum)
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
}
