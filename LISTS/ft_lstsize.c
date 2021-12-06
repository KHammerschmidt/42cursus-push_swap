/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:57:39 by khammers          #+#    #+#             */
/*   Updated: 2021/12/06 12:49:25 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prototype: int	ft_lstsize(t_list *lst);
**
** Counts the number of elements in a list.
**
** (1) while we are not at the end of the list yet: we iterate through the
** list by assigning lst the pointer to the next element.
** (2) at the same time whenever doing so, we increment the length.
** (3) we return the final length of the list.
*/
int	ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*tmp;

	length = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		length++;
	}
	return (length);
}
