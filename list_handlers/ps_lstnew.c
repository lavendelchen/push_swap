/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:45:08 by shaas             #+#    #+#             */
/*   Updated: 2022/02/14 20:40:54 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ps_lstnew(int num, t_list *stack_a, t_list *stack_b)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_exit(stack_a, stack_b);
	new->prev = NULL;
	new->num = num;
	new->next = NULL;
	return (new);
}
