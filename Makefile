# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khammers <khammers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 16:14:10 by khammers          #+#    #+#              #
#    Updated: 2021/12/01 12:40:51 by khammers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = main.c \
	utils.c \
	ft_create_nodes.c \
	ft_atoi_push_swap.c	\
	error.c	\
	input_testing.c	\
	swap_operations.c

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