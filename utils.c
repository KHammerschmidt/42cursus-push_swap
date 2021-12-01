/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:21 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/01 10:00:44 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_list **head)
{
	t_list	*node;
	t_list	*next;

	node = *head;
	while (node->next != NULL)
	{
		next = node->next;
		free(node);
		node = NULL;
		node = next;
	}
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

void	initiate(t_struct *data, int argc, char *argv[])
{
	data->argc = argc;
	data->argv = argv;
	data->counter = 0;
	data->tmp = NULL;
	data->nbr = 0;
	data->err_msg = 0;
	data->int_flag = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
}
