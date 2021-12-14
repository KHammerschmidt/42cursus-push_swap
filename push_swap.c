/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:54:49 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/14 12:59:36 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_list **head_a, t_list **head_b)
{
	int	len;

	len = ft_lstsize(*head_a);
	if (len == 2)
		sa(head_a, 1);
	else if (len == 3)
		ft_sort_three(head_a);
	else if (len <= 5)
		ft_sort_five(head_a, head_b);
	else if (len <= 100)
		ft_sort_hundred(head_a, head_b);
	else
		ft_sort_big(head_a, head_b);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error. Invalid number of arguments.\n", 1);
		return (EXIT_FAILURE);
	}
	init_stack_a(argv, &head_a);
	if (is_sorted(&head_a) == 1)
	{
		ft_free_lst(&head_a);
		return (0);
	}
	push_swap(&head_a, &head_b);
	ft_free_lst(&head_a);
	// system("leaks push_swap");
	return (0);
}
