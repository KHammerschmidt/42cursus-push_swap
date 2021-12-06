/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:54 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/06 16:05:21 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

/* Swap the first elements at the top of stack a. Do nothing if there is only
one or no elements. */
void	sa(t_list **head_a, int flag)
{
	int		tmp;

	tmp = (*head_a)->number;
	(*head_a)->number = (*head_a)->next->number;
	(*head_a)->next->number = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

/* Swap the first 2 elements at the top of stack b. Do nothing if there is
only one or no elements. */
void	sb(t_list **head_b, int flag)
{
	int		tmp;

	tmp = (*head_b)->number;
	(*head_b)->number = (*head_b)->next->number;
	(*head_b)->next->number = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

/* Swap sa and sb at the same time. */
void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a, 0);
	sb(head_b, 0);
	write(1, "ss\n", 3);
}
