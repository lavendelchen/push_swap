/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_combination.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:22:38 by shaas             #+#    #+#             */
/*   Updated: 2022/03/06 22:23:24 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



unsigned int	add_reverse_rotate(t_sort *sort)
{
	unsigned int	ret;

	if (sort->rra < sort->rrb)
	{
		sort->rrr = sort->rra;
		ret = sort->rrr + (sort->rrb - sort->rrr);
	}
	else
	{
		sort->rrr = sort->rrb;
		ret = sort->rrr + (sort->rra - sort->rrr);
	}
	return (ret);
}

unsigned int	add_rotate(t_sort *sort)
{
	unsigned int	ret;

	if (sort->ra < sort->rb)
	{
		sort->rr = sort->ra;
		ret = sort->rr + (sort->rb - sort->rr);
	}
	else
	{
		sort->rr = sort->rb;
		ret = sort->rr + (sort->ra - sort->rr);
	}
	return (ret);
}

void	find_shortest_combination(t_sort *sort, t_shortest_path *shortest_path)
{
	t_sums			sums;

	sums.ra_rrb = sort->ra + sort->rrb;
	shortest_path->length = sums.ra_rrb;
	shortest_path->type = 0;
	sums.rra_rb = sort->rra + sort->rb;
	if (sums.rra_rb < shortest_path->length)
	{
		shortest_path->length = sums.rra_rb;
		shortest_path->type = 1;
	}
	sums.ra_rb = add_rotate(sort);
	if (sums.ra_rb < shortest_path->length)
	{
		shortest_path->length = sums.ra_rb;
		shortest_path->type = 2;
	}
	sums.rra_rrb = add_reverse_rotate(sort);
	if (sums.rra_rrb < shortest_path->length)
	{
		shortest_path->length = sums.rra_rrb;
		shortest_path->type = 3;
	}
}
