/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:43:48 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/14 12:16:14 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

/* Take the first element at the top of b and put it at the top of a. Do
nothing if stack b is empty. */
void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*element;

	if (*head_b == NULL)
		return ;
	element = *head_b;
	if (element->next == NULL)
		*head_b = NULL;
	else
		*head_b = element->next;
	ft_lstadd_front(head_a, element);
	write(1, "pa\n", 3);
}

/* Take the first element of the top of a and put it at the top of b. Do
nothing if stack a is empty. */
void	pb(t_list **head_a, t_list **head_b)
{
	t_list	*element;

	if (*head_a == NULL)
		return ;
	element = *head_a;
	if (element->next == NULL)
		*head_a = NULL;
	else
		*head_a = element->next;
	ft_lstadd_front(head_b, element);
	write(1, "pb\n", 3);
}
