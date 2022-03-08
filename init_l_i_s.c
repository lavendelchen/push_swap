/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_l_i_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:39:24 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 00:17:24 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_l_i_s(t_list *stack_a)
{
	t_node	*search;
	t_node	*iter;

	iter = stack_a->tail;
	while (iter != NULL)
	{
		iter->l_i_s_length = 1;
		iter->l_i_s_next = NULL;
		search = iter->next;
		while (search != NULL)
		{
			if (search->rank > iter->rank && (iter->l_i_s_next == NULL || \
				search->l_i_s_length > iter->l_i_s_next->l_i_s_length))
			{
				iter->l_i_s_length = 1 + search->l_i_s_length;
				iter->l_i_s_next = search;
			}
			search = search->next;
		}
		iter = iter->prev;
	}
}

static t_node	*find_l_i_s(t_list *stack_a)
{
	t_node	*iter;
	t_node	*l_i_s;

	assign_l_i_s(stack_a);
	l_i_s = stack_a->head;
	iter = stack_a->head;
	while (iter != NULL)
	{
		if (iter->l_i_s_length > l_i_s->l_i_s_length)
			l_i_s = iter;
		iter = iter->next;
	}
	return (l_i_s);
}

void	init_l_i_s(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	t_node			*iter;
	t_node			*next;
	t_node			*l_i_s;
	unsigned int	i;

	i = 0;
	iter = stack_a->head;
	l_i_s = find_l_i_s(stack_a);
	while (i < numnum)
	{
		next = iter->next;
		if (iter == l_i_s)
		{
			rotate_a(stack_a, stack_b);
			l_i_s = l_i_s->l_i_s_next;
		}
		else
			push_b(stack_a, stack_b);
		iter = next;
		i++;
	}
}
