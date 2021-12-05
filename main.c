/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:54:49 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/05 16:23:59 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_sort_small(t_list **head_a, t_list **head_b)
// {
// 	t_list	*first_node;
// 	t_list	*second_node;
// 	t_list	*third_node;

// 	first_node = *head_a;
// 	second_node = (*head_a)->next;
// 	third_node = second_node->next;
// 	while (first_node->number > second_node->number)
// 	{
// 		sa(head_a, 1);
// 		ft_print_node(head_a, head_b);
// 	}
// 	while (1)
// 	{
// 		if (first_node->number < second_node->number
// 		&& first_node->number < third_node->number
// 		&& second_node->number < third_node->number)
// 			break ;
// 		sa(head_a, 1);
// 		ft_print_node(head_a, head_b);
// 	}
// 	if (!head_b)
// 		write(1, "1", 1);
// }

int	push_swap(t_list **head_a, t_list **head_b)
{
	int	len;

	len = ft_lstsize(*head_a);
	if (len == 3)
		ft_sort_small(head_a, head_b);
	return (0);
}

int main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
	{
		write(1, ERR_NR_ARGS, ft_strlen(ERR_NR_ARGS));
		return (EXIT_FAILURE);
	}
	init_stack_a(argv, &head_a);
	ft_print_node(&head_a, &head_b);
	push_swap(&head_a, &head_b);
	// pb(&head_a, &head_b);
	// system("leaks push_swap");
	return (0);
}
