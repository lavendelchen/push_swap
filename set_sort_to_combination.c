/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort_to_combination.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:50:45 by shaas             #+#    #+#             */
/*   Updated: 2022/03/06 22:23:31 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_sort_to_ra_rrb(t_sort *sort)
{
	sort->rr = 0;
	sort->rrr = 0;
	sort->rb = 0;
	sort->rra = 0;
}

static void	set_sort_to_rra_rb(t_sort *sort)
{
	sort->rr = 0;
	sort->rrr = 0;
	sort->rrb = 0;
	sort->ra = 0;
}

static void	set_sort_to_ra_rb(t_sort *sort)
{
	sort->ra = sort->ra - sort->rr;
	sort->rb = sort->rb - sort->rr;
	sort->rrr = 0;
	sort->rrb = 0;
	sort->rra = 0;
}

static void	set_sort_to_rra_rrb(t_sort *sort)
{
	sort->rra = sort->rra - sort->rrr;
	sort->rrb = sort->rrb - sort->rrr;
	sort->rr = 0;
	sort->rb = 0;
	sort->ra = 0;
}

void	set_sort_to_combination(t_shortest_path *shortest_path, t_sort *sort)
{
	if (shortest_path->type == 0)
		set_sort_to_ra_rrb(sort);
	else if (shortest_path->type == 1)
		set_sort_to_rra_rb(sort);
	else if (shortest_path->type == 2)
		set_sort_to_ra_rb(sort);
	else if (shortest_path->type == 3)
		set_sort_to_rra_rrb(sort);
	sort->sum = shortest_path->length;
}
