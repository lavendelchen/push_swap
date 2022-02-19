/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:58:12 by shaas             #+#    #+#             */
/*   Updated: 2022/02/19 13:56:06 by shaas            ###   ########.fr       */
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
	int				num;
	struct s_node	*next;
}				t_node;

typedef struct s_list
{
	t_node	*start;
	t_node	*end;
}				t_list;

/*needed to parse input*/
void	parse_input(int argc, char **argv, t_list *stack_a);
int		ps_atoi(const char *str, t_list *stack_a);
/*handle the two stacks*/
t_node	*ps_lstnew(int num, t_list *stack_a, t_list *stack_b); // 💭 all nodes wil be allocated
void	ps_lstinit(t_list *lst, t_node *new);
void	ps_lstadd_back(t_list *lst, t_node *new);
void	ps_lstadd_front(t_list *lst, t_node *new);
/*for when the program has to end*/
void	error_exit(t_list *stack_a, t_list *stack_b);
void	exit_cleanly(t_list *stack_a, t_list *stack_b, int is_failure);
/*operations*/
void	push_a(t_list *stack_a, t_list *stack_b);
void	push_b(t_list *stack_a, t_list *stack_b);
void	swap_a(t_list *stack_a);
void	swap_b(t_list *stack_b);
void	swap_ab(t_list *stack_a, t_list *stack_b);
void	rotate_a(t_list *stack_a);
void	rotate_b(t_list *stack_b);
void	rotate_ab(t_list *stack_a, t_list *stack_b);
void	reverse_rotate_a(t_list *stack_a);
void	reverse_rotate_b(t_list *stack_b);
void	reverse_rotate_ab(t_list *stack_a, t_list *stack_b);

#endif
