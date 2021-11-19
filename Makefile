# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 16:14:10 by khammers          #+#    #+#              #
#    Updated: 2021/11/19 15:50:18 by katharinaha      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC = main.c utils.c list_functions.c
OBJECTS = $(SRC:.c=.o)
LIBFT_OBJ = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(LIBFT_OBJ):
	make --directory=./libft

clean:
	rm -f $(OBJECTS)
	make clean -C ./libft

fclean:
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all