# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 22:43:00 by shaas             #+#    #+#              #
#    Updated: 2022/02/19 13:57:55 by shaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

COMP = gcc -Wall -Wextra -Werror -g

LIBFT = libft/libft.a

SRC := push_swap.c parse_input.c ps_atoi.c list_handlers/ps_lstnew.c \
list_handlers/ps_lstinit.c list_handlers/ps_lstadd_back.c error_exit.c 

OBJ = $(SRC:.c=.o)

ARG = 1 3 46  4556 45 3  2 2 3 3 23 4 5  5 4

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@printf $(YELLOW)"*--------object files created!---------*\n\n"$(RESET)
	$(COMP) $(OBJ) $(LIBFT) -o $(NAME)
	@printf $(LIGHTGREEN)"*--------executable created!-----------*\n\n"$(RESET)

%.o: %.c
	$(COMP) -o $@ -c $<

$(LIBFT):
	@printf $(LIGHTBLUE)"*--------checking libft...-------------*\n\n"$(RESET)
	@make -C ./libft

exec:
	@printf $(MAGENTA)"*--------executing program!------------*\n\n"$(RESET)
	./$(NAME) $(ARG)

both: $(NAME) exec

clean:
	rm -rf $(OBJ)
	make -C ./libft clean
	@printf $(RED)"*--------object files removed!---------*\n\n"$(RESET)

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean
	@printf $(RED)"*--------$(NAME) removed!--------------*\n\n"$(RESET)

re: fclean all

# text modifiers #
RED = "\e[31m"

GREEN = "\e[32m"

YELLOW = "\e[33m"

BLUE = "\e[34m"

MAGENTA = "\e[35m"

CYAN = "\e[36m"

LIGHTGRAY = "\e[37m"

DARKGRAY = "\e[90m"

LIGHTRED = "\e[91m"

LIGHTGREEN = "\e[92m"

LIGHTYELLOW = "\e[93m"

LIGHTBLUE = "\e[94m"

LIGHTMAGENTA = "\e[95m"

LIGHTCYAN = "\e[96m"

RED_BG = "\e[41m"

GREEN_BG = "\e[42m"

YELLOW_BG = "\e[43m"

BLUE_BG = "\e[44m"

MAGENTA_BG = "\e[45m"

CYAN_BG = "\e[46m"

LIGHTGRAY_BG = "\e[47m"

DARKGRAY_BG = "\e[100m"

LIGHTRED_BG = "\e[101m"

LIGHTGREEN_BG = "\e[102m"

LIGHTYELLOW_BG = "\e[103m"

LIGHTBLUE_BG = "\e[104m"

LIGHTMAGENTA_BG = "\e[105m"

LIGHTCYAN_BG = "\e[106m"

BOLD = "\e[1m"

ITALIC = "\e[3m"

UNDERLINED = "\e[4m"

RESET = "\e[0m"
