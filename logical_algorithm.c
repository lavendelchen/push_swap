/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:18:45 by shaas             #+#    #+#             */
/*   Updated: 2022/03/06 20:50:27 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* the way this works is, we try to find the next biggest number in stack_a
to the number we want to push from stack b. 
but, if the number is bigger than all the numbers on a, we can't find anything.
so, while iterating through the list, we also find the smallest number. and 
if our number is the biggest number, the smallest is "equal" to next biggest. */
t_node	*find_bottom(t_list *stack_a, t_node *node)
{
	t_node	*iter;
	t_node	*bottom;
	t_node	*smallest;

	iter = stack_a->head;
	bottom = NULL;
	smallest = stack_a->head;
	while (iter != NULL)
	{
		if ((bottom == NULL && iter->rank > node->rank) || \
			(iter->rank > node->rank && iter->rank < bottom->rank))
			bottom = iter;
		if (iter->rank < smallest->rank)
			iter = smallest;
		iter = iter->next;
	}
	if (bottom == NULL)
		bottom = smallest;
	return (bottom);
}

unsigned int	calculate_reverse_rotate(t_node *node, t_list *stack)
{
	t_node			*iter;
	unsigned int	reverse_rotate;

	iter = node;
	reverse_rotate = 0;
	while (iter != NULL && iter != stack->head)
	{
		iter = iter->next;
		reverse_rotate++;
	}
	return (reverse_rotate);
}
/*
what to do: 
- get algorithm to work (debugger)
- seperate functions in huuuge file!
- make small algos
- checker? nahh idc
*/

unsigned int	calculate_rotate(t_node *node, t_list *stack)
{
	t_node			*iter;
	unsigned int	rotate;

	iter = node;
	rotate = 0;
	while (iter != stack->head)
	{
		iter = iter->prev;
		rotate++;
	}
	return (rotate);
}

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

void	calculate_seperate_rotations(t_node *node, t_sort *sort, t_list *stack_a, t_list *stack_b)
{
	t_node	*bottom;

	printf("---------------------------------------------------------------------------------\n");
	bottom = find_bottom(stack_a, node);
	sort->rb = calculate_rotate(node, stack_b);
	sort->rrb = calculate_reverse_rotate(node, stack_b);
	sort->ra = calculate_rotate(bottom, stack_a);
	sort->rra = calculate_reverse_rotate(bottom, stack_a);
}

void	simple_paths(t_shortest_path *shortest_path, t_sort *sort)
{
	if (shortest_path->type == 0)
	{
		sort->rr = 0;
		sort->rrr = 0;
		sort->rb = 0;
		sort->rra = 0;
	}
	else if (shortest_path->type == 1)
	{
		sort->rr = 0;
		sort->rrr = 0;
		sort->rrb = 0;
		sort->ra = 0;
	}
}

void	complicated_paths(t_shortest_path *shortest_path, t_sort *sort)
{
	if (shortest_path->type == 2)
	{
		sort->ra = sort->ra - sort->rr;
		sort->rb = sort->rb - sort->rr;
		sort->rrr = 0;
		sort->rrb = 0;
		sort->rra = 0;
	}
	else if (shortest_path->type == 3)
	{
		sort->rra = sort->rra - sort->rrr;
		sort->rrb = sort->rrb - sort->rrr;
		sort->rr = 0;
		sort->rb = 0;
		sort->ra = 0;
	}
}

void	correct_sort_to_shortest_path(t_shortest_path *shortest_path, t_sort *sort)
{
	simple_paths(shortest_path, sort);
	complicated_paths(shortest_path, sort);
	sort->sum = sort->rr + sort->rrr + sort->rb + \
			sort->rrb + sort->ra + sort->rra;
}

t_shortest_path	find_shortest_path(t_sort *sort, t_shortest_path *shortest_path)
{
	t_sums	sums;

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
	if (sums.rra_rb < shortest_path->length)
	{
		shortest_path->length = sums.rra_rb;
		shortest_path->type = 2;
	}
	sums.rra_rrb = add_reverse_rotate(sort);
	if (sums.rra_rb < shortest_path->length)
	{
		shortest_path->length = sums.rra_rb;
		shortest_path->type = 3;
	}
}

void	calculate_sort_for_node(t_node *node, t_sort *sort, t_list *stack_a, t_list *stack_b)
{
	t_shortest_path	shortest_path;

	calculate_seperate_rotations(node, sort, stack_a, stack_b);
	find_shortest_path(sort, &shortest_path);
	correct_sort_to_shortest_path(&shortest_path, sort);
}

t_node	*calculate_sort(t_list *stack_a, t_list *stack_b)
{
	t_node	*iter;
	t_node	*shortest;

	shortest = stack_b->head;
	iter = stack_b->head;
	while (iter != NULL)
	{
		calculate_sort_for_node(iter, &iter->sort, stack_a, stack_b);
		printf("\e[32m%4d\e[0m rr: %4d, rrr: %4d, rb: %4d, rrb: %4d, ra: %4d, rra: %4d, sum: \e[91m%4d\e[0m\n", iter->rank, iter->sort.rr, iter->sort.rrr, iter->sort.rb, iter->sort.rrb, iter->sort.ra, iter->sort.rra, iter->sort.sum);
		printf("---------------------------------------------------------------------------------\n");
		if (iter->sort.sum < shortest->sort.sum)
			shortest = iter;
		iter = iter->next;
	}
	return (shortest);
}

void	do_operation_number_of_times(int operation, unsigned int times, t_list *stack_a, t_list *stack_b)
{
	void			(*function)(t_list *, t_list *);
	unsigned int	i;

	i = 0;
	if (operation == 0)
		function = &rotate_ab;
	else if (operation == 1)
		function = &reverse_rotate_ab;
	else if (operation == 2)
		function = &rotate_b;
	else if (operation == 3)
		function = &reverse_rotate_b;
	else if (operation == 4)
		function = &rotate_a;
	else if (operation == 5)
		function = &reverse_rotate_a;
	while (i < times)
	{
		function(stack_a, stack_b);
		i++;
	}
}

void	logical_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum)
{
	t_node	*sort;

	init_stacks(stack_a, stack_b, numnum);
	print_ranks(stack_a, stack_b);
	while (stack_b->head != NULL)
	{
		sort = calculate_sort(stack_a, stack_b);
		printf("\e[32m%4d\e[0m rr: %4d, rrr: %4d, rb: %4d, rrb: %4d, ra: %4d, rra: %4d, sum: %4d\n", sort->rank, sort->sort.rr, sort->sort.rrr, sort->sort.rb, sort->sort.rrb, sort->sort.ra, sort->sort.rra, sort->sort.sum);
		printf("---------------------------------------------------------------------------------\n");
		do_operation_number_of_times(0, sort->sort.rr, stack_a, stack_b);
		do_operation_number_of_times(1, sort->sort.rrr, stack_a, stack_b);
		do_operation_number_of_times(2, sort->sort.rb, stack_a, stack_b);
		do_operation_number_of_times(3, sort->sort.rrb, stack_a, stack_b);
		do_operation_number_of_times(4, sort->sort.ra, stack_a, stack_b);
		do_operation_number_of_times(5, sort->sort.rra, stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}

//python3 pyviz.py `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`