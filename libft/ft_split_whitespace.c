/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:27:05 by shaas             #+#    #+#             */
/*   Updated: 2022/02/24 17:47:23 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static int	ft_count(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (ft_whitespace(s[i]) == 0)
		{
			count++;
			while (ft_whitespace(s[i]) == 0 && s[i] != '\0')
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

static int	malloc_fail(char **split, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free(split[i]);
		i++;
	}
	free (split);
	return (0);
}

static int	ft_insert(const char *s, char **split)
{
	int	head;
	int	tail;
	int	count;

	head = 0;
	tail = 0;
	count = 0;
	while (s[head] != '\0')
	{
		if (ft_whitespace(s[head]) == 0)
		{
			tail = head;
			while (ft_whitespace(s[tail]) == 0 && s[tail] != '\0')
				tail++;
			split[count] = (char *)malloc(sizeof(char) * (tail - head + 1));
			if (split[count] == NULL)
				return (malloc_fail(split, count));
			ft_strlcpy(split[count], &s[head], tail - head + 1);
			count++;
			head = tail - 1;
		}
		head++;
	}
	split[count] = NULL;
	return (1);
}

char	**ft_split_whitespace(const char *s)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_count(s) + 1));
	if (split == NULL)
		return (split);
	if (ft_insert(s, split) == 0)
		return (NULL);
	return (split);
}
