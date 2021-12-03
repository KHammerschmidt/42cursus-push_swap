/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:36:10 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/03 18:50:09 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	error_handling(char **str, int j, t_list **head_a)
{
	while (str[j])
	{
		if (ft_isint(str[j]) != 0
			|| ft_isrange(ft_atoi(str[j]) != 0)
			|| check_dups(head_a, ft_atoi(str[j]) != 0))
		{
			ft_free_arr(str);
			ft_free_lst(head_a);
			write(1, "Error\n", 8);
			ft_error(2);
		}
		j++;
	}
	return (0);
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
		if (!str)
		{
			ft_free_lst(head_a);
			ft_error(2);
		}
		j = 0;
		while (str[j])
		{
			error_handling(str, j, head_a);
			node = ft_lstnew(ft_atoi(str[j]));
			ft_lstadd_back(head_a, node);
			j++;
		}
		ft_free_arr(str);
		i++;
	}
	return (0);
}
