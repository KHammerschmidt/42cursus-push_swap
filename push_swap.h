/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:07:50 by khammers          #+#    #+#             */
/*   Updated: 2021/12/02 21:13:18 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define ERR_NR_ARGS "Error: Invalid number of arguments\n"
# define ERR_INT_TYPE "Error: Arguments must be of type int\n"
# define ERR_MEM "Error: Memory allocation failed\n"
# define ERR_INT_RANGE "Error: Arguments are >INT_MAX/<INT_MIN\n"
# define ERR_DUP "Error: Arguments hold duplicates which cannot be sorted\n"

// typedef struct s_list
// {
// 	int				number;
// 	struct s_list	*next;
// 	// struct s_list	*prev;
// }			t_list;

typedef struct s_struct
{
	int			argc;
	char		**argv;
	int			counter_a;
	int			counter_b;
	char		**tmp;
	int			nbr;
	int			err_msg;
	int			int_flag;
	t_list		**stack_a;
	t_list		**stack_b;
}			t_struct;

/* Main */
int		main(int argc, char *argv[]);
int	init_stack_a(char *argv[], t_list **head_a);

int 	ft_print_node(t_list **head, t_struct *data);

/* Util functions, initialising and freeing allocated memory. */
void	initiate(t_struct *data, int argc, char *argv[]);
void	ft_free_arr(char **arr);
// void	ft_free_lst(t_struct *data);

/* Create list from input. */
int		fill_stack_a(t_struct *data);

/* Error function. */
int	ft_error(int msg);

/* Check input type int, int range & duplicates. */
int		ft_check_duplicates(t_list **head, t_list *node, t_struct *data);

int		test_transform_int(char *str);
int	ft_isrange(int nbr);
int ft_isint(char *str);
// int		nbr_in_range(int nbr, t_struct *data);
// int		ft_is_nbr(char *str, t_struct *data);

int		ft_atoi_ps(char *str, t_struct *data);

/* Swap functions */
void		sa(t_struct *data);
void		sb(t_struct *data);
void		ss(t_struct *data);

// /* List functions */
// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// void	ft_lstadd_front(t_list **lst, t_list *new);
// void	ft_lstclear(t_list **lst, void (*del)(void *));
// int		ft_lstsize(t_list *lst);
// void	ft_lstdelone(t_list *lst, void (*del)(void *));
// void	ft_lstiter(t_list *lst, void (*f)(void *));
// t_list	*ft_lstlast(t_list *lst);

#endif