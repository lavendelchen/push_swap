# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 22:43:00 by shaas             #+#    #+#              #
#    Updated: 2022/02/13 23:53:55 by shaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COMP = gcc -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(COMP) -o $@ -c $<
