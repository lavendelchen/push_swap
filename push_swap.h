/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:58:12 by shaas             #+#    #+#             */
/*   Updated: 2022/03/06 00:01:30 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap.h"
# include "libft/libft.h"

# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_sums
{
	unsigned int	ra_rrb;
	unsigned int	rra_rb;
	unsigned int	ra_rb;
	unsigned int	rra_rrb;
}				t_sums;

typedef struct s_sort
{
	unsigned int	rr;
	unsigned int	rrr;
	unsigned int	rb;
	unsigned int	rrb;
	unsigned int	ra;
	unsigned int	rra;
	unsigned int	sum;
}				t_sort;

typedef struct s_node
{
	struct s_node	*prev;
	int				num;
	unsigned int	rank;
	unsigned int	l_i_s_length;
	struct s_node	*l_i_s_next;
	t_sort			sort;
	struct s_node	*next;
}				t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
}				t_list;

/*utils*/
void			print_stacks(t_list *stack_a, t_list *stack_b);
void			print_ranks(t_list *stack_a, t_list *stack_b);
void			print_subsequence(t_node *l_i_s_start);
void			print_ranks_and_l_i_s(t_list *stack_a);
bool			is_sorted(t_list *stack, unsigned int numnum);
/*algorithm stuff*/
void			basic_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum);
void			random_sort(t_list *stack_a, t_list *stack_b, unsigned int numnum);
void			logical_algorithm(t_list *stack_a, t_list *stack_b, unsigned int numnum);
void			init_stacks(t_list *stack_a, t_list *stack_b, unsigned int numnum);
/*needed to parse input*/
void			parse_input(int argc, char **argv, t_list *stack_a);
int				ps_atoi(const char *str, t_list *stack_a);
unsigned int	assign_ranks(t_list *stack_a);
/*handle the two stacks*/
t_node			*ps_lstnew(int num, t_list *stack_a, t_list *stack_b); // 💭 all nodes wil be allocated
void			ps_lstinit(t_list *lst, t_node *new);
void			ps_lstadd_tail(t_list *lst, t_node *new);
void			ps_lstadd_head(t_list *lst, t_node *new);
void			ps_lstrm_head(t_list *lst);
void			ps_lstrm_tail(t_list *lst);
void			ps_lstfree(t_list *lst);
/*for when the program has to end*/
void			error_exit(t_list *stack_a, t_list *stack_b);
void			exit_cleanly(t_list *stack_a, t_list *stack_b, int is_failure);
/*operations*/
void			push_a(t_list *stack_a, t_list *stack_b);
void			push_b(t_list *stack_a, t_list *stack_b);
void			swap_a(t_list *stack_a);
void			swap_b(t_list *stack_b);
void			swap_ab(t_list *stack_a, t_list *stack_b);
void			rotate_a(t_list *stack_a, t_list *stack_b);
void			rotate_b(t_list *stack_a, t_list *stack_b);
void			rotate_ab(t_list *stack_a, t_list *stack_b);
void			reverse_rotate_a(t_list *stack_a, t_list *stack_b);
void			reverse_rotate_b(t_list *stack_a, t_list *stack_b);
void			reverse_rotate_ab(t_list *stack_a, t_list *stack_b);

#endif
