/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:14:53 by shaas             #+#    #+#             */
/*   Updated: 2022/02/22 18:05:15 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstadd_tail(t_list *lst, t_node *new)
{
	lst->tail->next = new;
	new->prev = lst->tail;
	lst->tail = new;
	lst->tail->next = NULL;
}
