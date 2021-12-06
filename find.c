/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:07:06 by khammers          #+#    #+#             */
/*   Updated: 2021/12/06 18:14:37 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_value(t_list **head, int val)
{
	t_list	*node;
	int		i;

	i = 0;
	node = *head;
	while (node->number != val)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int	find_median(t_list **head_a, int pos_min, int pos_max)
{
	t_list	*tmp;

	tmp = *head_a;
	while (tmp)
	{
		if (tmp->number != pos_min && tmp->number != pos_max)			//pos min / pos max
			return (tmp->number);
		tmp = tmp->next;
	}
	return (0);
}

int	find_next_smallest(t_list **head)
{
	int	min;
	int	min_next;
	t_list *tmp;

	min = find_smallest(head);
	tmp = *head;
	min_next = tmp->number;
	while (tmp)
	{
		if (tmp->number < min_next && tmp->number != min)
			min_next = tmp->number;
		tmp = tmp->next;
	}
	return (min_next);
}

int	find_smallest(t_list **head)
{
	t_list	*node;
	int		min;

	if (!*head)
		return (-1);
	node = *head;
	min = node->id;
	while (node)
	{
		if (node->id < min)
			min = node->id;
		node = node->next;
	}
	return (min);
}

int	find_next_largest(t_list **head)
{
	int	max;
	int	max_next;
	t_list *tmp;

	max = find_smallest(head);
	tmp = *head;
	max_next = tmp->number;
	while (tmp)
	{
		if (tmp->number < max_next && tmp->number != max)
			max_next = tmp->number;
		tmp = tmp->next;
	}
	return (max_next);
}

int	find_largest(t_list **head)
{
	t_list	*node;
	int		max;

	if (!*head)
		return (-1);
	node = *head;
	max = node->id;
	while (node)
	{
		if (node->id > max)
			max = node->id;
		node = node->next;
	}
	return (max);
}

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
