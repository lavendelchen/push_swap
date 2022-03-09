/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstrm_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:46:02 by shaas             #+#    #+#             */
/*   Updated: 2022/03/09 18:27:27 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstrm_head(t_list *lst)
{
	if (lst->head == NULL)
		return ;
	if (lst->head->next == NULL)
	{
		lst->head = NULL;
		lst->tail = NULL;
		return ;
	}
	lst->head = lst->head->next;
	lst->head->prev = NULL;
}
