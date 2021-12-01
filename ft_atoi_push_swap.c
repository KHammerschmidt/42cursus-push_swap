/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:48:21 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/01 12:21:22 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_ps(char *str, t_struct *data, t_list **head)
{
	int	i;
	int	sign;
	int	result;

	data->int_flag = 0;
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if ((str[i + 1] == '-') || (str[i + 1] == '+'))
			return (0);
		else if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		data->int_flag++;
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (data->int_flag == 0)
	{
		ft_error(1, head);
		exit(EXIT_FAILURE);
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		return (ft_error(3, head));
	return (result * sign);
}