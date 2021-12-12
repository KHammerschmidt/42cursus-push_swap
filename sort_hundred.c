/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:22:24 by khammers          #+#    #+#             */
/*   Updated: 2021/12/12 17:11:53 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_list **head_a, t_list **head_b, int chunk_max)
{
	t_list	*tmp;
	int		i;
	int		len;

	len = ft_lstsize(*head_a);
	i = 0;
	while (find_smallest(head_a) <= chunk_max)
	{
		tmp = *head_a;
		if (tmp->index <= chunk_max)
			pb(head_a, head_b);
		else
			ra(head_a, 1);
		i++;
	}
}

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
	while (tmp->index != find_largest(head_b))
	{
		tmp = tmp->next;
		i++;
	}
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

void	push_smallest_hundred(t_list **head_a, t_list **head_b, int chunk_max)
{
	t_list	*tmp;
	int		i;
	int		len;

	len = ft_lstsize(*head_a);
	i = 1;
	while (find_smallest(head_a) <= chunk_max)
	{
		tmp = *head_a;
		if (tmp->index <= chunk_max)
			pb(head_a, head_b);
		else
			ra(head_a, 1);
		i++;
	}
}

void	ft_sort_hundred(t_list **head_a, t_list **head_b)
{
	int	len;
	int	chunk;

	len = ft_lstsize(*head_a);
	chunk = (len / 5);

	while (ft_lstsize(*head_a) > (len / 5) * 2)
	{
		push_smallest_hundred(head_a, head_b, chunk);
		chunk += chunk;
	}
	while (*head_a)
		push_smallest(head_a, head_b);
	while (find_largest(head_b) >= (len / 5) * 4)
		pa(head_a, head_b);
	while (*head_b)
		push_largest(head_a, head_b);
}

// void	ft_sort_hundred(t_list **head_a, t_list **head_b)			// more than 900 operations
// {
// 	int	len;
// 	int	unteres_quartil;
// 	int	mid;
// 	int	oberes_quartil;

// 	len = ft_lstsize(*head_a);
// 	unteres_quartil = len / 4;
// 	mid = len / 2;
// 	oberes_quartil = (len / 4) * 3;
// 	while (ft_lstsize(*head_a) > oberes_quartil)
// 		push_smallest_hundred(head_a, head_b, unteres_quartil);
// 	while (ft_lstsize(*head_a) > mid)
// 		push_smallest_hundred(head_a, head_b, mid);
// 	while (ft_lstsize(*head_a) > unteres_quartil)
// 		push_smallest(head_a, head_b);
// 	while (ft_lstsize(*head_a) != 0)
// 		push_smallest(head_a, head_b);
// 	while (find_largest(head_b) != mid)
// 		pa(head_a, head_b);
// 	while (*head_b)
// 		push_largest(head_a, head_b);
// }

// void	ft_sort_hundred(t_list **head_a, t_list **head_b)
// {
// 	int	len;
// 	int	mid;

// 	len = ft_lstsize(*head_a);
// 	mid = len / 2;
// 	while (ft_lstsize(*head_a) > (len / 2) + 1)
// 		push_smallest_hundred(head_a, head_b, mid);
// 	while (ft_lstsize(*head_a) != 0)
// 		push_smallest(head_a, head_b);
// 	while (find_largest(head_b) != mid)
// 		pa(head_a, head_b);
// 	while (*head_b)
// 		push_largest(head_a, head_b);
// 	pa(head_a, head_b);
// }





// void	shortest_path(t_list **head_a, t_list **head_b)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		len;

// 	k = 0;
// 	i = find_id(head_a, find_smallest(head_a));
// 	j = find_id(head_a, find_next_smallest(head_a, find_smallest(head_a)));
// 	len = ft_lstsize(*head_a);
// 	// num_chunks = len / 10;
// 	if (i <= (len / num_chunks))
// 	{
// 		while (k++ < i)
// 			ra(head_a, 1);
// 	}
// 	else if (j <= (len / num_chunks))
// 	{
// 		while (k++ < j)
// 			rra(head_a, 1);
// 	}
// 	pb(head_a, head_b);
// }