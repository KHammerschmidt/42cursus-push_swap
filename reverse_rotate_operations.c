/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:43:07 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/03 21:20:38 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift down all elements of stack a by 1. The last element becomes the
first one. */
void	rra(t_list **head_a, int flag)
{
	t_list	*tmp;

	tmp = *head_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head_a;
	*head_a = (*head_a)->next;
	if (flag == 1)
		write(1, "rra\n", 4);
}

/* Shift down all elements of stack b by 1. The last element becomes the
first one. */
// int	rrb(t_list **head, t_struct *data)
// {

// 	if (flag == 1)
// 		write(1, "rrb\n", 4);
// }

// /* rra and rrb at the same time */
// int	rrr(t_list **head_a, t_list **head_b)
// {
// 	rra(&head_a, 0);
// 	rrb(head_b, 0);
// 	write(1, "rrr\n", 4);
// }