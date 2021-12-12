/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:41:58 by khammers          #+#    #+#             */
/*   Updated: 2021/12/12 17:10:45 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **head_a)
{
	t_list	*node;

	node = *head_a;
	if (node->index == find_smallest(head_a))
	{
		rra(head_a, 1);
		sa(head_a, 1);
	}
	else if (node->index == find_largest(head_a))
	{
		if (node->next->index == find_smallest(head_a))
			ra(head_a, 1);
		else
		{
			sa(head_a, 1);
			rra(head_a, 1);
		}
	}
	else
	{
		if (node->next->index == find_smallest(head_a))
			sa(head_a, 1);
		else if (node->next->index == find_largest(head_a))
			rra(head_a, 1);
	}
}