/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:15:09 by shaas             #+#    #+#             */
/*   Updated: 2022/02/14 17:22:43 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*curr2;

	if (del != NULL)
	{
		curr = *lst;
		while (curr != NULL)
		{
			curr2 = curr->next;
			ft_lstdelone(curr, del);
			curr = curr2;
		}
		*lst = NULL;
	}
}
