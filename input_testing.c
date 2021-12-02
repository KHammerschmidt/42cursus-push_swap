/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_testing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:59:24 by khammers          #+#    #+#             */
/*   Updated: 2021/12/02 20:50:26 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(t_list **head, t_list *node, t_struct *data)
{
	int		j;
	t_list	*tmp_node;

	j = 0;
	tmp_node = *head;
	if (data->counter_a == 1)
		return (EXIT_SUCCESS);
	while (tmp_node->next != NULL)
	{
		if (j == data->counter_a - 1)
			return (EXIT_SUCCESS);
		if (node->number == tmp_node->number)
			return (data->err_msg = 4);
		tmp_node = tmp_node->next;
		j++;
	}
	return (EXIT_SUCCESS);
}

// int	test_transform_int(char *str)
// {
// 	int	nbr;

// 	nbr = 0;
// 	if (ft_isdigit(argv[i] != 1) && ft_issign(argv[i] != 1)
// 		ft_error(1);
// 	nbr = ft_atoi(argv[i]);
// 	if (nbr < INT_MIN && nbr > INT_MAX)
// 		ft_error(3);
// 	return (nbr);
// }

int	ft_isrange(int nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		ft_error(3);
	return (0);
}

int ft_isint(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]!= 0 && ft_issign(str[i]) != 0))
			ft_error(1);
		i++;
	}
	return (0);
}
