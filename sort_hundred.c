/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:22:24 by khammers          #+#    #+#             */
/*   Updated: 2021/12/14 13:05:39 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* All numbers which are smaller than chunk_max are being pushed to the other
stack. */
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

/* All numbers within the percentile are being pushed to the other
stack. */
void	push_percentile(t_list **head_a, t_list **head_b, int chunk_max)
{
	t_list	*tmp;
	int		len;

	len = ft_lstsize(*head_a);
	while (find_smallest(head_a) <= chunk_max)
	{
		tmp = *head_a;
		if (tmp->index <= chunk_max)
			pb(head_a, head_b);
		else
			ra(head_a, 1);
	}
}

void	ft_print_node(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_node_a;
	t_list	*tmp_node_b;

	tmp_node_a = *head_a;
	tmp_node_b = *head_b;
	printf("A				B\n");
	printf("---				---\n");
	while (tmp_node_a || tmp_node_b)
	{
		if (tmp_node_a)
		{
			ft_putnbr_fd(tmp_node_a->number, 1);
			tmp_node_a = tmp_node_a->next;
		}
		ft_putstr_fd("				", 1);
		if (tmp_node_b)
		{
			ft_putnbr_fd(tmp_node_b->number, 1);
			tmp_node_b = (tmp_node_b)->next;
		}
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("\n", 1);
}

/* Sorting algorithm for numbers > 5 & <= 100. */
void	ft_sort_hundred(t_list **head_a, t_list **head_b)
{
	int	lower_quartile;
	int	upper_quartile;
	int	mid;
	int	len;
	t_list	*tmp;

	tmp = *head_a;
	len = ft_lstsize(*head_a);
	mid = len / 2;
	lower_quartile =  len / 4;
	upper_quartile = (len / 4) * 3;
	while (ft_lstsize(*head_a) > upper_quartile)
	{
		// printf("\n len >>>%d\n", ft_lstsize(*head_a));
		if (tmp->index < lower_quartile)
			pb(head_a, head_b);
		else
			ra(head_a, 1);
		// push_quartile(head_a, head_b, lower_quartile);
		// ft_print_node(head_a, head_b);
	}
	while (ft_lstsize(*head_a) > mid)
	{
		if (tmp->index < mid)
			pb(head_a, head_b);
		else
			ra(head_a, 1);
		// ft_print_node(head_a, head_b);
	}
		// push_quartile(head_a, head_b, mid);
	// while (ft_lstsize(*head_a) > lower_quartile)
	// 	push_smallest(head_a, head_b);
	// while (ft_lstsize(*head_a) != 0)
	// 	push_smallest(head_a, head_b);
	// while (find_largest(head_b) != mid)
	// 	pa(head_a, head_b);
	// while (*head_b)
	// 	push_largest(head_a, head_b);
}

// void	ft_sort_hundred(t_list **head_a, t_list **head_b)			// more than 900 operations
// {
// 	int		quartile;
// 	t_list	*tmp;

// 	tmp = *head_a;
// 	quartile = ft_lstsize(*head_a) / 5;
// 	while (*head_a)
// 	{
// 		while (find_smallest(head_a) <= quartile && *head_a)
// 		{
// 			if (tmp->index <= quartile)
// 				pb(head_a, head_b);
// 			else
// 				ra(head_a, 1);
// 			ft_print_node(head_a, head_b);
// 		}
// 		quartile += quartile;
// 	}
// 	while (*head_b)
// 		push_largest(head_a, head_b);
// }


			// if (ft_lstsize(*head_a) < quartile)
			// {
			// 	push_quartile(head_a, head_b, quartile);
			// 	ft_print_node(head_a, head_b);
			// }


// void	ft_sort_hundred(t_list **head_a, t_list **head_b)
// {
// 	int	len;
// 	int	chunk;

// 	len = ft_lstsize(*head_a);
// 	chunk = (len / 5);

// 	while (ft_lstsize(*head_a) > (len / 5))
// 	{
// 		push_smallest_hundred(head_a, head_b, chunk);
// 		chunk += chunk;
// 	}
// 	while (*head_a)
// 		push_smallest(head_a, head_b);
// 	while (find_largest(head_b) >= (len / 5) * 4)
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
// 		push_percentile(head_a, head_b, mid);
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