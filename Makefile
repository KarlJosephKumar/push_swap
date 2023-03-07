# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 19:56:46 by kakumar           #+#    #+#              #
#    Updated: 2023/03/06 15:12:46 by kakumar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

SRC = error_handling.c rules_a.c rules_b.c common_rules.c update_arguments.c calculate.c \
sorting.c sort_util.c execute.c	list_utils.c create_stacks.c index.c half.c \
moves.c execute_decision.c

OBJECTFILES = $(SRC:.c=.o)

NAME = push_swap.a

LIBFT = libft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)libft.a $(NAME)
	cc -c $(SRC) $(FLAGS)
	ar rcs $(NAME) $(OBJECTFILES)
	cc $(FLAGS) $(NAME) main.c -o push_swap

clean:
	rm -f $(OBJECTFILES)
	$(MAKE) clean -C $(LIBFT)

fclean:
	rm -f $(OBJECTFILES)
	rm -f $(NAME)
	rm -f push_swap
	$(MAKE) fclean -C $(LIBFT)

re: fclean all
