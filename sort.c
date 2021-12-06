/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:22:24 by khammers          #+#    #+#             */
/*   Updated: 2021/12/06 19:28:57 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_five(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *head_a;
	tmp_b = *head_b;
	pb(head_a, head_b);
	pb(head_a, head_b);
	while (tmp_a)
	{
		tmp_a->id = 1;
		ft_get_indx(tmp_a, head_a);
		tmp_a = tmp_a->next;
	}
	ft_print_node(head_a, head_b);
	ft_sort_three(head_a);
	ft_print_node(head_a, head_b);

	// tmp_a = *head_a;
	// if (tmp_a->id > tmp_a->next->id)
	// 	sa(head_a, 1);
	// ft_print_node(head_a, head_b);
	// tmp_b = *head_b;
	// if (tmp_b->id > tmp_b->next->id)
	// 	sb(head_b, 1);

	// if (tmp_b->id > tmp_a->id)
	// {
	// 	pa(head_a, head_b);
	// 	sa(head_a, 1);
	// }
	// else if (tmp_b->id < tmp_a->id)
	// 	pa(head_a, head_b);
	// else

	ft_print_node(head_a, head_b);
}

void	ft_sort_three(t_list **head_a)
{
	t_list	*node;

	node = *head_a;
	if (node->id == 0)
	{
		rra(head_a, 1);
		sa(head_a, 1);
	}
	else if (node->id == 1)
	{
		if (node->next->id == 0)
			sa(head_a, 1);
		else if (node->next->id == 2)
			rra(head_a, 1);
	}
	else if (node->id == 2)
	{
		if (node->next->id == 0)
			ra(head_a, 1);
		else if (node->next->id == 1)
		{
			sa(head_a, 1);
			rra(head_a, 1);
		}
	}
}
