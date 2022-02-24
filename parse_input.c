/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:02:26 by shaas             #+#    #+#             */
/*   Updated: 2022/02/24 17:47:37 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_for_duplicates(t_list *stack_a)
{
	t_node	*node;

	node = stack_a->head;
	while (node != stack_a->tail)
	{
		if (node->num == stack_a->tail->num)
			error_exit(stack_a, NULL);
		node = node->next;
	}
}

static void	handle_string_of_ints(t_list *stack_a, char *str)
{
	char	**split;
	t_node	*new;
	int		i;

	i = 0;
	split = ft_split_whitespace(str);
	if (split == NULL)
		error_exit(stack_a, NULL);
	while (split[i] != NULL)
	{
		new = ps_lstnew(ps_atoi(split[i], stack_a), stack_a, NULL);
		ps_lstadd_tail(stack_a, new);
		check_for_duplicates(stack_a);
		i++;
	}
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	parse_input(int argc, char **argv, t_list *stack_a)
{
	int		i;
	t_node	*new;

	if (argc < 2)
		error_exit(stack_a, NULL);
	new = ps_lstnew(ps_atoi(argv[1], stack_a), stack_a, NULL),
	ps_lstinit(stack_a, new);
	if (ft_strchr(argv[1], ' '))
		handle_string_of_ints(stack_a, ft_strchr(argv[1], ' '));
	i = 2;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			handle_string_of_ints(stack_a, argv[i]);
		else
		{
			new = ps_lstnew(ps_atoi(argv[i], stack_a), stack_a, NULL);
			ps_lstadd_tail(stack_a, new);
			check_for_duplicates(stack_a);
		}
		i++;
	}
}
