/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:20:54 by shaas             #+#    #+#             */
/*   Updated: 2022/03/01 21:52:28 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b) // needs to be removed when submitting, norm error
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
				printf("       n/a  ");
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
				printf("  n/a       ");
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

void	print_ranks(t_list *stack_a, t_list *stack_b) // needs to be removed when submitting, norm error
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
				printf("       n/a  ");
			else
				printf("            ");
		}
		else
		{
			printf("%10d  ", iter_a->rank);
			iter_a = iter_a->next;
		}
		printf("|");
		if (stack_b == NULL || iter_b == NULL)
		{
			if (stack_b == NULL)
				printf("  n/a       ");
			else
				printf("            ");
		}
		else
		{
			printf("  %-10d", iter_b->rank);
			iter_b = iter_b->next;
		}
		printf("\n");
	}
	printf("\n");
}

void	print_subsequence(t_list *stack_a) // needs to be removed when submitting, norm error
{
	t_list *stack_b;
	t_node *iter_a;
	t_node *iter_b;

	stack_b = NULL;
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
				printf("       n/a  ");
			else
				printf("            ");
		}
		else
		{
			printf("%10d  ", iter_a->rank);
			iter_a = iter_a->path;
		}
		printf("|");
		if (stack_b == NULL || iter_b == NULL)
		{
			if (stack_b == NULL)
				printf("  n/a       ");
			else
				printf("            ");
		}
		else
		{
			printf("  %-10d", iter_b->rank);
			iter_b = iter_b->path;
		}
		printf("\n");
	}
	printf("\n");
}
