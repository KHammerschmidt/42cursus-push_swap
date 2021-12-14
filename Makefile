# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khammers <khammers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 16:14:10 by khammers          #+#    #+#              #
#    Updated: 2021/12/14 17:19:39 by khammers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = push_swap.c \
	init_stack.c	\
	input_handling.c	\
	free_mem.c	\
	sort_small.c	\
	sort_big.c	\
	sorting_utils.c	\
	./operations/swap_operations.c	\
	./operations/push_operations.c	\
	./operations/rotate_operations.c	\
	./operations/reverse_rotate_operations.c

OBJECTS = $(SRC:.c=.o)
LIBFT_OBJ = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT_OBJ):
	make --directory=./libft

clean:
	rm -f $(OBJECTS)
	make clean -C ./libft

fclean:
	rm -f $(NAME)
	rm -f $(OBJECTS)
	make fclean -C ./libft

re: fclean all