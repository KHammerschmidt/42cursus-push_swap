/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:07:06 by khammers          #+#    #+#             */
/*   Updated: 2021/12/14 17:23:01 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds the smallest number by its id and returns the id. */
int	find_smallest(t_list **head)
{
	t_list	*node;
	int		min;

	if (!*head)
		return (-1);
	node = *head;
	min = node->index;
	while (node)
	{
		if (node->index < min)
			min = node->index;
		node = node->next;
	}
	return (min);
}

/* Finds the largest number by its id and returns the id. */
int	find_largest(t_list **head)
{
	t_list	*node;
	int		max;

	if (!*head)
		return (-1);
	node = *head;
	max = node->index;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}

void	push_smallest(t_list **head_src, t_list **head_dst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *head_src;
	while (tmp->index != find_smallest(head_src))
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

/* Largest number of a stack is being pushed to the other one. */
void	push_largest(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *head_b;
	if (!(*head_b)->next)
	{
		pa(head_a, head_b);
		*head_b = NULL;
		return ;
	}
	while (tmp->index != find_largest(head_b) && i++)
		tmp = tmp->next;
	if (i >= (ft_lstsize(*head_b) / 2))
	{
		while (i++ != ft_lstsize(*head_b))
			rrb(head_b, 1);
	}
	else
	{
		while (i-- != 0)
			rb(head_b, 1);
	}
	pa(head_a, head_b);
}

/* Checks if the stack is already sorted, if so returns 1
otherwise 0. */
int	is_sorted(t_list **head_a)
{
	t_list	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(*head_a);
	if (!*head_a)
		return (-1);
	tmp = *head_a;
	while (tmp->next)
	{
		if (tmp->number < tmp->next->number)
		{
			tmp = tmp->next;
			i++;
		}
		else
			break ;
	}
	if (++i == len)
		return (1);
	return (0);
}
