/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:36:10 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/14 12:58:53 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sets an index for the element's content in comparison to the already
existing elements of the list. */
void	ft_get_indx(t_list *node, t_list **head_a)
{
	t_list	*tmp;

	if (!*head_a)
		return ;
	tmp = *head_a;
	while (tmp)
	{
		if (node->number < tmp->number)
			tmp->index++;
		if (node->number > tmp->number)
			node->index++;
		tmp = tmp->next;
	}
}

/* Splits the cmd line input and checks if it is valid. If yes, create
a new node, adds it to the end of stack a and sets an index for the
node's content. */
int	init_stack_a(char *argv[], t_list **head_a)
{
	int		i;
	int		j;
	char	**str;
	t_list	*node;

	i = 1;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			error_handling(str[j], head_a);
			node = ft_lstnew(ft_atoi(str[j]));
			ft_lstadd_back(head_a, node);
			ft_get_indx(node, head_a);
			j++;
		}
		ft_free_arr(str);
		i++;
	}
	return (0);
}
