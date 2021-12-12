/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:48:11 by khammers          #+#    #+#             */
/*   Updated: 2021/12/12 19:17:10 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(t_list **head_a)
{
	int		len;
	int		len_max;
	t_list	*tmp;

	len = 0;
	len_max = 0;
	tmp = *head_a;
	while (tmp->next)
	{
		len = 0;
		while (tmp->number)
		{
			len++;
			tmp->number >>= 1;
			if (len > len_max)
				len_max = len;
		}
		tmp = tmp->next;
	}
	return (len_max);
}

void	ft_sort_big(t_list **head_a, t_list **head_b)
{
	int		i;
	int		max_len;
	t_list	*tmp;

	i = 0;
	tmp = *head_a;
	while (i++ < ft_lstsize(*head_a))
		max_len = count_bits(head_a);
	i = max_len;
	while (max_len != 0)
	{
		if ()		//long bitshifting loops
	// https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
	}

	// int	len;
	// int	chunk;

	// len = ft_lstsize(*head_a);
	// chunk = (len / 11);

	// while (ft_lstsize(*head_a) > (len / 11) * 9)
	// {
	// 	push_smallest_hundred(head_a, head_b, chunk);
	// 	chunk += chunk;
	// }
	// while (*head_a)
	// 	push_smallest(head_a, head_b);
	// while (find_largest(head_b) >= (len / 11) * 9)
	// 	pa(head_a, head_b);
	// while (*head_b)
	// 	push_largest(head_a, head_b);
}