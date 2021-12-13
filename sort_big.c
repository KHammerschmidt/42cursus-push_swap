/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:48:11 by khammers          #+#    #+#             */
/*   Updated: 2021/12/13 20:26:51 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(t_list **head_a)
{
	int		len;
	int		len_max;
	int		save;
	t_list	*tmp;

	len = 0;
	len_max = 0;
	tmp = *head_a;
	while (tmp->next)
	{
		save = tmp->index;
		len = 0;
		while (save)
		{
			len++;
			save >>= 1;
			if (len > len_max)
				len_max = len;
		}
		tmp = tmp->next;
	}
	return (len_max);
}

void	ft_putnbr(int x)
{
	ft_putnbr_fd(x, 1);
}
void	ft_sort_big(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	int		max_bits;
	int		j;
	int		k;
	int		save;

	tmp = *head_a;
	save = 0;
	max_bits = count_bits(head_a);
	// printf("print\n");
	// ft_lstiter(*head_a, ft_putnbr);
	// printf("end\n");
	// printf(">>>>>>>>%d\n", max_bits);
	k = 0;
	j = ft_lstsize(*head_a);
	// ft_print_node(head_a, head_b);

	while (k < max_bits)				// k == position I want to compare
	{
		while (j-- > 0 && is_sorted(head_a) == 0)
		{
			save = (*head_a)->index;
			// printf("<<<<<<%d", save);
			if ((((save) >> k) & 1) == 0)
				pb(head_a, head_b);
			else
				ra(head_a, 1);
			// ft_print_node(head_a, head_b);
		}
		k++;
		int d = ft_lstsize(*head_b);
		// int save_a;
		while (d-- != 0)
		{
			save = (*head_b)->index;
			if ((((save) >> k) & 1) != 0 || k == max_bits)
				pa(head_a, head_b);
			else
				rb(head_b, 1);
			// ft_print_node(head_a, head_b);
		}
		j = ft_lstsize(*head_a);
	}
		//long bitshifting loops
	// https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

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