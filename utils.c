/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:21 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/19 17:12:22 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_nbr(int nbr)
{
	if (nbr > INT_MIN && nbr < INT_MAX)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

void	ft_error(int msg)
{
	if (msg == 1)
		ft_putstr_fd("Error\nSome arguments aren't integers\n", STDERR_FILENO);		// ft_error_msg(1, data);
	
	// ft_free_lst();
	exit(EXIT_FAILURE);
}

int	ft_error_msg_ints(char *input, t_struct *data)
{
	int	nbr;
	int	j;

	j = 0;
	nbr = ft_atoi(input);
	if (ft_isdigit(nbr) != 0)
		ft_putstr_fd("Error\nSome arguments aren't integers\n", STDERR_FILENO);		// ft_error_msg(1, data);
	if (nbr < -32767) 		//INT_MIN) //has to be defined
		ft_putstr_fd("Error\nSome arguments are bigger than an int\n", STDERR_FILENO);	// ft_error_msg(2, data);
	if (nbr > 32767) 		//INT_MIN) //has to be defined
		ft_putstr_fd("Error\nSome arguments are smaller than an int\n", STDERR_FILENO);	// ft_error_msg(3, data);
	while (data->list_nbrs[j])
	{
		if (nbr == data->list_nbrs[j])
		{
			ft_putstr_fd("Error\nThere are duplicates in your input, this cannot be sorted", STDERR_FILENO);	// ft_error_msg(4, data);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	return (nbr);
}

void	initiate(t_struct *data, int argc, char *argv[])
{
    data->argc = argc;
	data->argv = argv;
	data->counter = 0;
	// data->list_nbrs = 0;
	// t_list	stack_a;
	// t_list	stack_b;
	// t_list	*list;
}