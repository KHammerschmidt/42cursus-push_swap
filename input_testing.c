/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_testing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:59:24 by khammers          #+#    #+#             */
/*   Updated: 2021/12/06 13:07:36 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(t_list **head_a, char *str)
{
	int		num;
	int		len;
	int		i;
	t_list	*tmp_node;

	i = 0;
	len = ft_lstsize(*head_a);
	if (len <= 1)
		return (0);
	num = ft_atoi(str);
	tmp_node = *head_a;
	while (tmp_node)
	{
		if (tmp_node->number == num && i != (len - 1))
			return (-1);
		else
			tmp_node = tmp_node->next;
		i++;
	}
	return (0);
}

int	ft_isrange(int nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (-1);
	return (0);
}

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[0] == '+'))
		{
			if (ft_isdigit(str[i + 1]) == 0)
				i++;
			else
				return (-1);
		}
		if (ft_isdigit(str[i]) == 0)
			i++;
		else
			return (-1);
	}
	return (0);
}
