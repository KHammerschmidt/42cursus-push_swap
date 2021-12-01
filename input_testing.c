/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_testing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:59:24 by khammers          #+#    #+#             */
/*   Updated: 2021/12/01 11:58:58 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(t_list **head, t_list *node, t_struct *data)
{
	int		j;
	t_list	*tmp_node;

	j = 0;
	tmp_node = *head;
	if (data->counter == 1)
		return (EXIT_SUCCESS);
	while (tmp_node->next != NULL)
	{
		if (j == data->counter - 1)
			return (EXIT_SUCCESS);
		if (node->number == tmp_node->number)
			return (data->err_msg = 4);
		tmp_node = tmp_node->next;
		j++;
	}
	return (EXIT_SUCCESS);
}

int		nbr_in_range(int nbr, t_struct *data)
{
	if (nbr < INT_MIN && nbr > INT_MAX)
		return (data->err_msg = 3);
	return (EXIT_SUCCESS);
}

int	ft_is_nbr(char *str, t_struct *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (ft_isdigit(str[i]) != 1)
			return (data->err_msg = 1);
		i++;
	}
	return (0);
}


