/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:48:00 by shaas             #+#    #+#             */
/*   Updated: 2022/02/23 19:48:08 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_list *stack_a)
{
	long long	rank;
	t_node		*iter;
	t_node		*smallest;
	//t_node		*smaller;

	rank = 0;
	iter = stack_a->head;
	smallest = stack_a->head;
	while (iter != NULL)
	{
		if (iter->num < smallest->num)
			smallest = iter;
		iter = iter->next;
	}
	smallest->rank = rank;
	printf("smallest number: %d, has rank %lld\n", smallest->num, smallest->rank);
}