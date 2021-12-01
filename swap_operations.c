/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:54 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/01 12:48:20 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first elements at the top of stack a. Do nothing if there is only
one or no elements. */
int	sa(t_struct *data)
{
	t_list	*second_node;
	t_list	*first_node;
	int		nbr_first_node;
	int		nbr_second_node;

	nbr_first_node = 0;
	nbr_second_node = 0;
	if (data->counter <= 1)
		return (0);
	first_node = *data->stack_a;
	nbr_first_node = first_node->number;
	second_node = *data->stack_a;
	second_node = second_node->next;
	nbr_second_node = second_node->number;
	first_node->number = nbr_second_node;
	second_node->number = nbr_first_node;
	write(1, "sa\n", 3);
	return (0);
}

/* Swap the first 2 elements at the top of stack b. Do nothing if there is
only one or no elements. */
int	sb(t_struct *data)
{
	t_list	*second_node;
	t_list	*first_node;
	int		nbr_first_node;
	int		nbr_second_node;

	nbr_first_node = 0;
	nbr_second_node = 0;
	if (data->counter <= 1)
		return (0);
	first_node = *data->stack_b;
	nbr_first_node = first_node->number;
	second_node = *data->stack_b;
	second_node = second_node->next;
	nbr_second_node = second_node->number;
	first_node->number = nbr_second_node;
	second_node->number = nbr_first_node;
	write(1, "sb\n", 3);
	return (0);
}

// int	ss(t_list **head, t_struct *data)
// {
// 	swap sa and sb at the same time.
// }




