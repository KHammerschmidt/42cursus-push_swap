/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:36:10 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/06 17:16:04 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_handling(char *str, t_list **head_a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isint(str) != 0
			|| ft_isrange(ft_atoi(str) != 0)
			|| check_dups(head_a, str) != 0)
		{
			free(str);
			ft_free_lst(head_a);
			write(1, "Error\n", 7);
			exit(1);
		}
		i++;
	}
	return (0);
}

void	ft_get_indx(t_list *node, t_list **head_a)
{
	t_list	*tmp;

	if (!*head_a)
		return ;
	tmp = *head_a;
	while (tmp)
	{
		if (node->number < tmp->number)
			tmp->id++;
		if (node->number > tmp->number)
			node->id++;
		tmp = tmp->next;
	}
}

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
