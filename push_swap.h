/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:58:12 by shaas             #+#    #+#             */
/*   Updated: 2022/02/14 20:43:20 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap.h"
# include "libft/libft.h"

# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	struct s_node	*prev;
	int		num;
	struct s_node	*next;
}				t_node;

typedef struct s_list
{
	t_node	*start;
	t_node	*end;
}				t_list;

void	parse_input(int argc, char **argv, t_list *stack_a);
t_node	*ps_lstnew(int num, t_list *stack_a, t_list *stack_b); // 💭 all nodes wil be allocated
void	ps_lstinit(t_list *lst, int num, t_list *stack_a, t_list *stack_b);
void	ps_lstadd_back(t_list *lst, t_node *new);
void	error_exit(t_list *stack_a, t_list *stack_b);
void	exit_cleanly(t_list *stack_a, t_list *stack_b, int is_failure);

#endif
