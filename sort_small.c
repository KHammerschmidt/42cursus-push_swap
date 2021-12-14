/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:41:58 by khammers          #+#    #+#             */
/*   Updated: 2021/12/14 12:56:35 by khammers         ###   ########.fr       */
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

void	ft_sort_five(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		i;

	i = 0;
	tmp_a = *head_a;
	tmp_b = *head_b;
	push_smallest(head_a, head_b);
	push_smallest(head_a, head_b);
	if (is_sorted(head_a) != 1)
		ft_sort_three(head_a);
	pa(head_a, head_b);
	pa(head_a, head_b);
}
