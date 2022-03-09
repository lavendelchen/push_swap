/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstrm_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:35:24 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 18:00:57 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstrm_tail(t_list *lst)
{
	if (lst->tail == NULL)
		return ;
	if (lst->tail->prev == NULL) // case that there is only on element right now
	{
		lst->head = NULL;
		lst->tail = NULL;
		return ;
	}
	lst->tail = lst->tail->prev;
	lst->tail->next = NULL;
}
