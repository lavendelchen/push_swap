/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:14:53 by shaas             #+#    #+#             */
/*   Updated: 2022/02/22 19:50:52 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstadd_tail(t_list *lst, t_node *new)
{
	if (new == NULL)
		return ;
	if (lst->head == NULL)
	{
		ps_lstinit(lst, new);
		return ;
	}
	lst->tail->next = new;
	new->prev = lst->tail;
	lst->tail = new;
	lst->tail->next = NULL;
}
