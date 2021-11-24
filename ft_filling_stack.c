/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:02:06 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/24 14:03:43 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_filling_stack(t_struct *data, t_list **head)
{
	t_list	*tmp_lst;

	tmp_lst = *head;
	while (tmp_lst->next != *head)
	{

		tmp_lst = tmp_lst->next;
	}
	return (EXIT_SUCCESS);
}