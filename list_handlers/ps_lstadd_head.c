/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:12:36 by shaas             #+#    #+#             */
/*   Updated: 2022/02/15 20:50:57 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstadd_head(t_list *lst, t_node *new)
{
	lst->head->prev = new;
	new->next = lst->head;
	lst->head = new;
	lst->head->prev = NULL;
}
