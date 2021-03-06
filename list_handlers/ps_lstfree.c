/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:15:09 by shaas             #+#    #+#             */
/*   Updated: 2022/02/23 22:08:38 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstfree(t_list *lst)
{
	t_node	*curr;

	if (lst != NULL)
	{
		curr = lst->head;
		while (curr != NULL)
		{
			free(curr);
			curr = curr->next;
		}
	}
}
