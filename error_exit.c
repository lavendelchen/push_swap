/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:32:42 by shaas             #+#    #+#             */
/*   Updated: 2022/02/24 18:12:25 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_cleanly(t_list *stack_a, t_list *stack_b, int is_failure)
{
	ps_lstfree(stack_a);
	ps_lstfree(stack_b);
	exit(is_failure);
}

void	error_exit(t_list *stack_a, t_list *stack_b)
{
	//ft_putendl_fd("Error", 2);
	write(2, "Error\n", 6);
	exit_cleanly(stack_a, stack_b, EXIT_FAILURE);
}
