/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:20:54 by shaas             #+#    #+#             */
/*   Updated: 2022/03/04 14:09:41 by shaas            ###   ########.fr       */
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

void	print_subsequence(t_node *l_i_s_start) // needs to be removed when submitting, norm error
{
	t_node *iter_a;

	if (l_i_s_start == NULL)
		return ;
	iter_a = l_i_s_start;
	printf("        \e[1mstack a\e[0m        \n");
	printf("  subsequence of %d \n", l_i_s_start->rank);
	printf("-----------------------\n");
	while (1)
	{
		if (iter_a == NULL)
			break ;
		else
		{
			printf("  %10d  ", iter_a->rank);
			iter_a = iter_a->l_i_s_next;
		}
		printf("\n");
	}
	printf("\n");
}

void	print_ranks_and_l_i_s(t_list *stack_a) // needs to be removed when submitting, norm error
{
	t_node *iter_a;

	if (stack_a != NULL)
		iter_a = stack_a->head;
	else
		iter_a = NULL;
	printf("        \e[1mstack a\e[0m        \n");
	printf("     l_i_s | rank \n");
	printf("  ---------------------\n");
	while (1)
	{
		if (iter_a == NULL)
			break ;
		else
		{
			printf("\e[3m%10d\e[0m | %-10d ", iter_a->l_i_s_length, iter_a->rank);
			iter_a = iter_a->next;
		}
		printf("\n");
	}
	printf("\n");
}