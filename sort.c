/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:22:24 by khammers          #+#    #+#             */
/*   Updated: 2021/12/09 17:25:25 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_sort_big(t_list **head_a, t_list **head_b)
// {
// 	t_list	*tmp_a;
// 	t_list	*tmp_b;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	tmp_a = *head_a;
// 	tmp_b = *head_b;
// 	while (i < ft_lstsize(*head_a) - 1)
// 	{
// 		while (tmp_a->id != find_smallest(head_a))
// 			tmp_a = tmp_a->next;
// 		while (j++ != find_value(head_a, tmp_a->number))
// 				ra(head_a, 1);
// 		i++;
// 		pb(head_a, head_b);
// 	}
// }

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

void	push_smaller_mid(t_list **head_a, t_list **head_b, int mid)
{
	t_list	*tmp;
	int		i;
	int		len;

	len = ft_lstsize(*head_a);
	i = 0;
	while (i != len + 1) //find_smallest(head_a) <= mid)
	{
		tmp = *head_a;
		if (tmp->id <= mid)
			pb(head_a, head_b);
		else
			ra(head_a, 1);
		i++;
		ft_print_node(head_a, head_b);
	}
}

void	push_rest(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(head_a);
	tmp = *head_a;
	while (*head_a != NULL)
	{
		i = find_value(head_a, find_smallest(head_a));
		if (i-- < (len / 2))
		{
			while (i != 0)
				ra(head_a, 1);
		}

	}
}

// if (i < (ft_lstsize(*head_a) / 2))
// 	ra(head_a, 1);
// else
// 	rra(head_a, 1);
// pb(head_a, head_b);
// i = 0;

void	ft_sort_hundred(t_list **head_a, t_list **head_b)
{
	int		mid;
	int		len;

	len = ft_lstsize(*head_a);
	mid = len / 2;
	ft_print_node(head_a, head_b);
	push_smaller_mid(head_a, head_b, mid);
	// push_smaller_mid(head_a, head_b, mid);
	// while (*head_b)
	// 	pa(head_a, head_b);
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

void	ft_sort_three(t_list **head_a)
{
	t_list	*node;

	node = *head_a;
	if (node->id == find_smallest(head_a))
	{
		rra(head_a, 1);
		sa(head_a, 1);
	}
	else if (node->id == find_largest(head_a))
	{
		if (node->next->id == find_smallest(head_a))
			ra(head_a, 1);
		else
		{
			sa(head_a, 1);
			rra(head_a, 1);
		}
	}
	else
	{
		if (node->next->id == find_smallest(head_a))
			sa(head_a, 1);
		else if (node->next->id == find_largest(head_a))
			rra(head_a, 1);
	}
}

// void	push_smaller_mid(t_list **head_a, t_list **head_b, int mid)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		min;
// 	int		next_min;

// 	int		moves_ra;
// 	int		moves_rra;

// 	moves_ra = 0;
// 	moves_rra = ft_lstsize(*head_a) / 2;
// 	t_list	*tmp;
// 	tmp = *head_a;
// 	while (find_smallest(head_a) <= mid)
// 	{
// 		while (moves_ra != (ft_lstsize(*head_a) / 2))
// 		{
// 			if (tmp->id < mid)
// 			{
		// 		moves_ra++;

		// 	}
		// 	tmp = tmp->next;
		// }
		// while (moves_rra != ft_lstsize(*head_a))
		// {
		// 	if (tmp->id < mid)
		// 		moves_rra;
		// 	tmp = tmp->next;
		// }
		// if (moves_ra < moves_rra)
		// {
		// 	while (k++ < i)
		// 		ra(head_a, 1);
		// }
		// else
		// {
		// 	while (k++ < j)
		// 		rra(head_a, 1);
		// }
		// pb(head_a, head_b);

		// min = find_smallest(head_a);
		// next_min = find_next_smallest(head_a, min);
		// k = 0;
		// i = find_id(head_a, min);
		// j = find_id(head_a, next_min);
		// printf(">>>>%d %d<<<<\n", i, j);
		// if (i <= mid)
		// {
		// 	while (k++ < i)
		// 		ra(head_a, 1);
		// 	pb(head_a, head_b);
		// 	ft_print_node(head_a, head_b);
		// }
		// if (j >= mid)
		// {
		// 	while (k++ < j)
		// 		rra(head_a, 1);
		// 	pb(head_a, head_b);
		// 	ft_print_node(head_a, head_b);
		// }
// 	}
// }








	// t_list	*tmp_a;
	// t_list	*tmp_b;
	// int		nbr_chunks;
	// int		len;
	// int		k;

	// k = 1;
	// tmp_a = *head_a;
	// tmp_b = *head_b;
	// nbr_chunks = 5;
	// len = ft_lstsize(*head_a);
	// while (k < 6)
	// {
	// 	if (k == 1)
	// 	{
	// 		chunk_min = 0;
	// 		chunk_max = len / 5;
	// 	}
	// 	else)
	// 	{
	// 		chunk_min = chunk_max + 1;
	// 		chunk_max = (len / 5) * k;
	// 	}
	// }

	// while ((*head_a)->next)
	// 	split_chunks(head_a, head_b);


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