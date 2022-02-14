/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:25:39 by shaas             #+#    #+#             */
/*   Updated: 2022/02/14 22:03:15 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*checks if char is certain type of character*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/*converts letter to different case*/
int		ft_tolower(int c);
int		ft_toupper(int c);

/*print stuff to certain file descriptor*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*finds char in mem*/
void	*ft_memchr(const void *s, int c, size_t n);

/*finds char in string*/
char	*ft_strchr(const char *s, int c);
/*finds digit in string*/
char	*ft_strdigit(const char *s);

/*finds last occurence of char in string*/
char	*ft_strrchr(const char *s, int c);

/*makes mem one specific char*/
void	*ft_memset(void *b, int c, size_t len);

/*makes mem '\0'*/
void	ft_bzero(void *s, size_t n);

/*compare memory, return difference*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*compare strings*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*copies mem to other mem*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*better memcpy, mems can overlap*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/*copies string to other string (choose to end before)*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*💭 copies string into allocated mem*/
char	*ft_strdup(const char *s1);

/*appends string to other string*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*💭 allocates combined string*/
char	*ft_strjoin(const char *s1, const char *s2);

/*returns length of string*/
size_t	ft_strlen(const char *s);

/*finds string in other string*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*converts string to integer*/
int		ft_atoi(const char *str);

/*💭 converts integer to string*/
char	*ft_itoa(int n);

/*💭 allocates mem + sets it to '\\0'*/
void	*ft_calloc(size_t count, size_t size);

/*💭 allocates part of string (choose freely)*/
char	*ft_substr(const char *s, unsigned int start, size_t len);

/*💭 allocates trimmed string (complicated lol,
meaning it trims chars from set from front and end)*/
char	*ft_strtrim(const char *s1, const char *set);

/*💭 splits string into substrings, allocates them*/
char	**ft_split(const char *s, char c);

/*applies function to every char of string*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*💭 applies function to every char of string, allocates result*/
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

#endif
