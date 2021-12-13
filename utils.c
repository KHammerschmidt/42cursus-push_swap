/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:21 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/13 14:11:50 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Frees every element of a list pointed to by the stack's head. */
void	ft_free_lst(t_list **stack_head)
{
	t_list	*tmp;

	tmp = *stack_head;
	while (tmp)
	{
		stack_head = &(*stack_head)->next;
		free(tmp);
		tmp = *stack_head;
	}
}

/* Frees every element of an array. */
void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

/* Prints both stack a and stac b next to each other. */
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

/* Prints every index of an element. */
void	print_idx(t_list **head_a)
{
	t_list *tmp;

	tmp = *head_a;
	while (tmp)
	{
		printf("num %d || index: %d <- index\n", tmp->number, tmp->index);
		tmp = tmp->next;
	}
}
