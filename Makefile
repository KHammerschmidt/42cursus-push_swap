# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khammers <khammers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 16:14:10 by khammers          #+#    #+#              #
#    Updated: 2021/12/06 17:29:28 by khammers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = push_swap.c \
	utils.c \
	init_stack_a.c \
	error.c	\
	input_testing.c	\
	./operations/swap_operations.c	\
	./operations/push_operations.c	\
	./operations/rotate_operations.c	\
	./operations/reverse_rotate_operations.c	\
	find.c	\
	sort.c

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