# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 22:43:00 by shaas             #+#    #+#              #
#    Updated: 2022/02/13 23:56:17 by shaas            ###   ########.fr        #
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

exec:
	./$(NAME)

both: $(NAME) exec

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
