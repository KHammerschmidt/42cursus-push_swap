/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:48:11 by khammers          #+#    #+#             */
/*   Updated: 2021/12/11 16:51:00 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_list **head_a, t_list **head_b)
{
	int	len;
	int	chunk;

	len = ft_lstsize(*head_a);
	chunk = (len / 10);

	while (ft_lstsize(*head_a) > (len / 10) * 2)
	{
		push_smallest_hundred(head_a, head_b, chunk);
		chunk += chunk;
	}
	while (*head_a)
		push_smallest(head_a, head_b);
	while (find_largest(head_b) >= (len / 10) * 9)
		pa(head_a, head_b);
	while (*head_b)
		push_largest(head_a, head_b);
}