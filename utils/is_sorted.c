/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:08:00 by shaas             #+#    #+#             */
/*   Updated: 2022/03/01 20:08:20 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_sorted(t_list *stack, unsigned int numnum)
{
	t_node				*iter;
	unsigned int		rank;

	rank = 0;
	iter = stack->head;
	while (iter != NULL) // checks from 0 till the list ends (not very specific usecase)
	{
		if (iter->rank != rank)
			return (false);
		iter = iter->next;
		rank++;
	}
	if (rank < numnum)
		return (false);
	return (true);
}
