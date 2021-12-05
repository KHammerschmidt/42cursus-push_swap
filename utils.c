/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:21 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/05 16:13:19 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_list **stack_head)
{
	t_list	*tmp;

	tmp = *stack_head;
	while (tmp)
	{
		stack_head = &(*stack_head)->next;
		free(tmp);
		tmp = *stack_head;
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

// void	initiate(t_struct *data, int argc, char *argv[])
// {
// 	data->argc = argc;
// 	data->argv = argv;
// 	data->counter_a = 0;
// 	data->counter_b = 0;
// 	data->tmp = NULL;
// 	data->nbr = 0;
// 	data->err_msg = 0;
// 	data->int_flag = 0;
// 	*data->stack_a = NULL;
// 	*data->stack_b = NULL;
// }
