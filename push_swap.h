/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:07:50 by khammers          #+#    #+#             */
/*   Updated: 2021/11/19 17:03:50 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int			content;
	t_struct	*previous;
	t_struct	*next;
}			t_list;

// typedef struct s_stack
// {
// 	t_list	list_b;
// 	t_list	list_a;
// }			t_stack;

typedef struct s_struct
{
	int		argc;
	char	**argv;
	t_list	**list;
	int		counter;

	// int		*list_nbrs;
	t_list	stack_a;
	t_list	stack_b;
	t_list	*list;
}			t_struct;

/* Main */
int		main(int argc, char *argv[]);

/* Util functions. */
void	initiate(t_struct *data, int argc, char *argv[]);
int		ft_error_msg_ints(char *input, t_struct *data);

/* Setting up lists with nodes */
int	ft_count_nodes(t_struct *data, t_list *list);
int		ft_create_node(t_struct *data, int content, t_list **head);

/* List functions */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);

#endif