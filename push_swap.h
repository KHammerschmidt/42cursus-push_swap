/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:07:50 by khammers          #+#    #+#             */
/*   Updated: 2021/11/12 17:20:09 by khammers         ###   ########.fr       */
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
	void			*content;
	struct s_list	*next;
}	t_list;

// typedef struct s_stack
// {
// 	t_list	list_b;
// 	t_list	list_a;
// }			t_stack;

typedef struct s_struct
{
	int		argc;
	char	**argv;
	int		*list_nbrs;
	int		counter;
	t_list	stack_a;
	t_list	stack_b;
	t_list	*list;
}				t_struct;


int		main(int argc, char *argv[]);
void	ft_initialise(int argc, char *argv[], t_struct *data);
int		ft_handle_input(t_struct *data);
int		ft_count_digits(t_struct *data);
int		ft_error_msg_ints(char *input, t_struct *data);
void	ft_free_arr(char **arr);

#endif