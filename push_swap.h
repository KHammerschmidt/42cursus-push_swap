/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:07:50 by khammers          #+#    #+#             */
/*   Updated: 2021/12/14 17:32:13 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
// # include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

int		main(int argc, char *argv[]);
int		push_swap(t_list **head_a, t_list **head_b);

/* Input handling and initialising stack a with a simply linked list. */
int		init_stack_a(char *argv[], t_list **head_a);
void	ft_get_indx(t_list *node, t_list **head_a);
int		error_handling(char *str, t_list **head_a);

/* Util functions of printing steps and freeing memory space. */
void	ft_free_arr(char **arr);
void	ft_free_lst(t_list **stack_head);

/* Sorting functions */
int		is_sorted(t_list **head_a);
void	ft_sort_three(t_list **head_a);
void	ft_sort_five(t_list **head_a, t_list **head_b);
void	ft_sort_big(t_list **head_a, t_list **head_b);

/* Pushing a specific value to the other stack. */
void	push_smallest(t_list **head_src, t_list **head_dst);
void	push_largest(t_list **head_a, t_list **head_b);
void	push_chunk(t_list **head_a, t_list **head_b, int chunk_max);

/* Sorting helper, e.g. finding a specific value or smallest/largest
number. */
int		find_smallest(t_list **head_a);
int		find_largest(t_list **head);

// void	ft_sort_big(t_list **head_a, t_list **head_b);
// void	push_smaller_mid(t_list **head_a, t_list **head_b, int mid);
// void	push_smallest_hundred(t_list **head_a, t_list **head_b, int chunk_max);
// void	shortest_path(t_list **head_a, t_list **head_b, int mid);

/* Push_swap functions */
void	sa(t_list **head_a, int flag);
void	sb(t_list **head_b, int flag);
void	ss(t_list **head_a, t_list **head_b);
void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);
void	ra(t_list **head_a, int flag);
void	rb(t_list **head_b, int flag);
void	rr(t_list **head_a, t_list **head_b);
void	rra(t_list **head_a, int flag);
void	rrb(t_list **head_b, int flag);
void	rrr(t_list **head_a, t_list **head_b);

#endif