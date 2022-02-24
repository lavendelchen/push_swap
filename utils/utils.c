/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:20:54 by shaas             #+#    #+#             */
/*   Updated: 2022/02/24 23:05:45 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_node *iter_a;
	t_node *iter_b;

	if (stack_a != NULL)
		iter_a = stack_a->head;
	else
		iter_a = NULL;
	if (stack_b != NULL)
		iter_b = stack_b->head;
	else
		iter_b = NULL;
	printf("    stack a | stack b  \n");
	printf("  ---------------------\n");
	while (1)
	{
		if (iter_a == NULL && iter_b == NULL)
			break ;
		if (stack_a == NULL || iter_a == NULL)
		{
			if (stack_a == NULL)
				printf("         N/A");
			else
				printf("            ");
		}
		else
		{
			printf("%10d  ", iter_a->num);
			iter_a = iter_a->next;
		}
		printf("|");
		if (stack_b == NULL || iter_b == NULL)
		{
			if (stack_b == NULL)
				printf(" N/A        ");
			else
				printf("            ");
		}
		else
		{
			printf("  %-10d", iter_b->num);
			iter_b = iter_b->next;
		}
		printf("\n");
	}
	printf("\n");
}

bool	is_sorted(t_list *stack, unsigned int numnum)
{
	t_node				*iter;
	unsigned int		rank;

	rank = 0;
	iter = stack->head;
	while (iter != NULL) // checks from 0 till the list ends (not very specific usecase)
	{
		if (iter->rank != rank)
			return (false);
		iter = iter->next;
		rank++;
	}
	if (rank < numnum)
		return (false);
	return (true);
}
