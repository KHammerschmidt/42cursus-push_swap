/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:07:50 by khammers          #+#    #+#             */
/*   Updated: 2021/11/24 11:15:28 by katharinaha      ###   ########.fr       */
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

typedef struct s_list
{
	int			number;
	struct s_list	*prev;
	struct s_list	*next;
}			t_list;

typedef struct s_struct
{
	int			argc;
	char		**argv;
	t_list		**list;
	int			counter;
	char		**tmp;
	int			nbr;
	int			err_msg;
	int			int_flag;
	// t_list	stack_a;
	// t_list	stack_b;
	// int		**int_arr;
}			t_struct;

/* Main */
int		main(int argc, char *argv[]);
void	initiate(t_struct *data, int argc, char *argv[]);
int		ft_create_list(t_struct *data, t_list **head);
int		ft_check_duplicates(t_list **head, t_list *node, t_struct *data);

/* Util functions. */
int	ft_error(int msg);
int		ft_duplicates(t_struct *data, int *nbr);
int		nbr_in_range(int nbr);
void	ft_free_arr(char **arr);

int		ft_atoi_ps(char *str, t_struct *data);
int 	ft_print_node(t_list **head, t_struct *data);
int		ft_check_duplicates(t_list **head, t_list *node, t_struct *data);


// /* Setting up lists with nodes */
// int		ft_count_nodes(t_struct *data, t_list *list);
// int		ft_create_node(t_struct *data, int content, t_list **head);
// int		ft_split_arg_and_check_int(t_struct *data, t_list *list);

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