/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:07:50 by khammers          #+#    #+#             */
/*   Updated: 2021/12/11 16:50:31 by khammers         ###   ########.fr       */
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
# define ERR_NR_ARGS "Error: Invalid number of arguments\n"
# define ERR_INT_TYPE "Error: Arguments must be of type int\n"
# define ERR_MEM "Error: Memory allocation failed\n"
# define ERR_INT_RANGE "Error: Arguments are >INT_MAX/<INT_MIN\n"
# define ERR_DUP "Error: Arguments hold duplicates which cannot be sorted\n"

// typedef struct s_struct
// {
// 	int			argc;
// 	char		**argv;
// 	int			counter_a;
// 	int			counter_b;
// 	char		**tmp;
// 	int			nbr;
// 	int			err_msg;
// 	int			int_flag;
// 	t_list		**stack_a;
// 	t_list		**stack_b;
// }			t_struct;

/* Main */
int		main(int argc, char *argv[]);
int		init_stack_a(char *argv[], t_list **head_a);
int		error_handling(char *str, t_list **head_a);
void	ft_free_lst(t_list **stack_head);
int		check_dups(t_list **head_a, char *str);
void	ft_print_node(t_list **head_a, t_list **head_b);
void	ft_free_arr(char **arr);

int		find_smallest(t_list **head_a);
int		find_next_smallest(t_list **head, int comp);
int		find_largest(t_list **head);
int		find_next_largest(t_list **head);

int		is_sorted(t_list **head_a);
void	print_idx(t_list **head_a);
int		find_mid(t_list **head_a, int min, int max);
int		find_value(t_list **head, int val);
void	ft_get_indx(t_list *node, t_list **head_a);
void	ft_sort_three(t_list **head_a);
void	 ft_sort_five(t_list **head_a, t_list **head_b);
// void	ft_sort_big(t_list **head_a, t_list **head_b);
int		find_id(t_list **head, int id);
void	ft_sort_hundred(t_list **head_a, t_list **head_b);
void	push_smaller_mid(t_list **head_a, t_list **head_b, int mid);
void	push_smallest_hundred(t_list **head_a, t_list **head_b, int chunk_max);
// void	shortest_path(t_list **head_a, t_list **head_b);
void	shortest_path(t_list **head_a, t_list **head_b, int mid);
void	push_smallest(t_list **head_src, t_list **head_dst);
void	ft_sort_big(t_list **head_a, t_list **head_b);
void	push_largest(t_list **head_a, t_list **head_b);
/* Check input type int, int range & duplicates. */
// int		ft_check_duplicates(t_list **head, t_list *node, t_struct *data);

// int		test_transform_int(char *str);
int		ft_isrange(int nbr);
int		ft_isint(char *str);
// int		ft_atoi_ps(char *str, t_struct *data);

/* Swap functions */
void		sa(t_list **head_a, int flag);
void		sb(t_list **head_b, int flag);
void		ss(t_list **head_a, t_list **head_b);

void		pa(t_list **head_a, t_list **head_b);
void		pb(t_list **head_a, t_list **head_b);

void		ra(t_list **head_a, int flag);
void		rb(t_list **head_b, int flag);
void		rr(t_list **head_a, t_list **head_b);

void		rra(t_list **head_a, int flag);
void		rrb(t_list **head_b, int flag);
void		rrr(t_list **head_a, t_list **head_b);

#endif