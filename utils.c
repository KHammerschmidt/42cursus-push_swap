/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:21 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/02 18:05:16 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_struct *data)
{
	t_list	*node;
	t_list	*next;

	if (data->stack_a != NULL)
	{
		node = *data->stack_a;
		while (node->next != NULL)
		{
			next = node->next;
			free(node);
			node = NULL;
			node = next;
		}
	}
	if (data->stack_b != NULL)
	{
		node = *data->stack_b;
		while (node->next != NULL)
		{
			next = node->next;
			free(node);
			node = NULL;
			node = next;
		}
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
	data->counter_a = 0;
	data->counter_b = 0;
	data->tmp = NULL;
	data->nbr = 0;
	data->err_msg = 0;
	data->int_flag = 0;
	*data->stack_a = NULL;
	*data->stack_b = NULL;
}
