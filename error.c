/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:00:49 by khammers          #+#    #+#             */
/*   Updated: 2021/12/01 10:44:49 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_error(int msg, t_list **head)
// {
// 	if (msg == 0)
// 		ft_putstr_fd("Error: Invalid number of arguments", STDERR_FILENO);
// 	if (msg == 1)
// 		ft_putstr_fd("Error: Arguments must be of type int\n", STDERR_FILENO);
// 	if (msg == 2)
// 		ft_putstr_fd("Error: Memory allocation failed\n", STDERR_FILENO);
// 	if (msg == 3)
// 		ft_putstr_fd("Error: Arguments are >INT_MAX/<INT_MIN\n", STDERR_FILENO);
// 	if (msg == 4)
// 		ft_putstr_fd("Error: Arguments hold duplicates which cannot be sorted\n", STDERR_FILENO);
// 	if (msg == 5)
// 		ft_putstr_fd("Error: Creating doubly linked list element was unsuccesful", STDERR_FILENO);
// 	ft_free_lst(head);
// 	return (msg);
// }

int	ft_error(int msg, t_list **head)
{
	if (msg == 0)
		ft_putstr_fd(ERR_NR_ARGS, STDERR_FILENO);
	if (msg == 1)
		ft_putstr_fd(ERR_INT_TYPE, STDERR_FILENO);
	if (msg == 2)
		ft_putstr_fd(ERR_MEM, STDERR_FILENO);
	if (msg == 3)
		ft_putstr_fd(ERR_INT_RANGE, STDERR_FILENO);
	if (msg == 4)
		ft_putstr_fd(ERR_DUP, STDERR_FILENO);
	if (msg == 5)
		ft_putstr_fd("Error: Creating doubly linked list element was unsuccesful", STDERR_FILENO);
	ft_free_lst(head);
	exit (EXIT_FAILURE);
	// return (msg);
}