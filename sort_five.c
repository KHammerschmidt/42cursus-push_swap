/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:42:55 by khammers          #+#    #+#             */
/*   Updated: 2021/12/11 15:56:21 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_smallest(t_list **head_src, t_list **head_dst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *head_src;
	while (tmp->id != find_smallest(head_src))
	{
		tmp = tmp->next;
		i++;
	}
	if (ft_lstsize(*head_src) == 1)
		pb(head_src, head_dst);
	if (i >= (ft_lstsize(*head_src) / 2))
	{
		while (i++ != ft_lstsize(*head_src))
			rra(head_src, 1);
	}
	else
	{
		while (i-- != 0)
			ra(head_src, 1);
	}
	pb(head_src, head_dst);
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