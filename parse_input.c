/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:02:26 by shaas             #+#    #+#             */
/*   Updated: 2022/02/14 22:55:47 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_whitespace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static int	ps_atoi(const char *str, t_list *stack_a)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (ps_whitespace(*str) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10;
		i = i + (*str - '0');
		str++;
	}
	i = i * sign;
	if (i < INT_MIN || i > INT_MAX)
		error_exit(stack_a, NULL);
	return ((int)i);
}


static void	check_for_errors(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 1;
	j = 0;
	while(i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
				error_exit(NULL, NULL);
			j++;
		}
		j = 0;
		i++;
	}
}

static void	handle_string_of_ints(t_list *stack_a, char *str)
{
	t_node	*new;
	char	*buf;

	while (str != NULL)
	{
		printf("\e[96mhere?\e[0m\n");
		printf("str: [%s]\n", str);
		buf = ft_strtrim(str, " ");
		new = ps_lstnew(ps_atoi(str, stack_a), stack_a, NULL);
		ps_lstadd_back(stack_a, new);
		printf("buf: [%s]\n", buf);
		str = ft_strchr(buf, ' ');
		printf("str after: [%s]\n", str);
		free(buf);
	}
}

/*
./push_swap 1 2 3 4 5 6 "  848  444   8  28383   838  " 3324 55 " 383   29  44422 2 " 3
here?
str: [  848  444   8  28383   838  ]
buf: [848  444   8  28383   838]
str after: [  444   8  28383   838]
here?
str: [  444   8  28383   838]
buf: [444   8  28383   838]
str after: [   8  28383   838]
here?
str: [   8  28383   838]
buf: [8  28383   838]
str after: [  28383   838]
here?
str: [  28383   838]
buf: [28383   838]
str after: [   838]
here?
str: [   838]
buf: [838]
str after: [(null)]
here?
str: [ 383   29  44422 2 ]
buf: [383   29  44422 2]
str after: [   29  44422 2]
here?
str: [   29  44422 2]
buf: [29  44422 2]
str after: [  44422 2]
here?
str: [  44422 2]
buf: [44422 2]
str after: [ 2]
here?
str: [ 2]
buf: [2]
str after: [(null)]
1
2
3
4
5
6
848
8
28383
28383
838
3324
55
383
29
422
2
3
*/

void	parse_input(int argc, char **argv, t_list *stack_a)
{
	int		i;
	t_node	*new;

	check_for_errors(argc, argv);
	ps_lstinit(stack_a, ps_atoi(argv[1], stack_a), stack_a, NULL);
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
			ps_lstadd_back(stack_a, new); //mult num in str, duplicates
		}
		i++;
	}
	t_node *buf;
	buf = stack_a->start;
	while (buf != NULL)
	{
		printf("%d\n", buf->num);
		buf = buf->next;
	}
}
