/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:15:35 by shaas             #+#    #+#             */
/*   Updated: 2022/02/22 18:03:41 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstinit(t_list *lst, t_node *new)
{
	new->prev = NULL;
	new->next = NULL;
	lst->head = new;
	lst->tail = new;
}
