/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:15:35 by shaas             #+#    #+#             */
/*   Updated: 2022/02/14 21:43:45 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstinit(t_list *lst, int num, t_list *stack_a, t_list *stack_b)
{
	t_node	*first;

	first = ps_lstnew(num, stack_a, stack_b);
	lst->start = first;
	lst->end = first;
}
