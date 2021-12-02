/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:43:48 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/01 19:37:55 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Take the first element at the top of b and put it at the top of a. Do
nothing if b is empty. */
int	pa(t_list **head, t_struct *data)
{
	t_list	*element_a;
	t_list	*element_b;
	t_list	*tmp_a;
	t_list	*tmp_b;

	element_a = *data->stack_a;
	tmp_a = *data->stack_a;
	element_b = *data->stack_b;
	tmp_b = *data->stack_b;

	data->stack_a = element_b;
	tmp = tmp->next;
	element_b->next = tmp;



}

/* Take the first element of the top of a and put it at the top of b. Do
nothing if a is empty. */
int	pb(t_list **head, t_struct *data)
{
	t_list	*element:


}
