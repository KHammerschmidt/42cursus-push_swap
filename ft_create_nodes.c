/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:36:10 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/24 11:37:39 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(t_list **head, t_list *node, t_struct *data)
{
	int	j;
	t_list	*tmp_node;

	j = 0;
	tmp_node = *head;
	if (data->counter == 1)
		return (EXIT_SUCCESS);
	while (tmp_node->next != *head)			// while (j++ < data->counter - 1)
	{
		if (node->number == tmp_node->number)
			return (data->err_msg = 4);
		tmp_node = tmp_node->next;
	}
	return (EXIT_SUCCESS);
}

int 	ft_print_node(t_list **head, t_struct *data)
{
	t_list 	*tmp_node;
	char	*content_list;

	tmp_node = *head;
	content_list = NULL;
	while (tmp_node->next != *head && data->counter != 1)
	{
		content_list = ft_itoa(tmp_node->number);
		write(1, content_list, ft_strlen(content_list));
		write(1, " | ", 3);
		tmp_node = tmp_node->next;
		free(content_list);
		content_list = NULL;
	}
	content_list = ft_itoa(tmp_node->number);
	write(1, content_list, ft_strlen(content_list));
	free(content_list);
	content_list = NULL;
	return (EXIT_SUCCESS);
}

static int	ft_create_node(t_struct *data, int nbr, t_list **head)
{
	t_list	*node;
	t_list	*previous_node;
	int		j;

	j = 0;
	previous_node = *head;
	node = ft_calloc(1, sizeof(t_list));
	if (node == NULL)
		return (data->err_msg = 5);
	data->counter++;
	node->number = nbr;
	node->prev = NULL;
	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
	{
		node->next = *head;
		(*head)->prev = node;
		if (previous_node->next == NULL)
			previous_node->next = node;
		else
		{
			while (previous_node->next != *head) 		// while (j++ != data->counter)	
				previous_node = previous_node->next;  
			previous_node->next = node;
		}
		node->prev = previous_node;
	}
	// printf("%p <--- root  ||  ", head);
	// printf("%d <--- int of element || %p <--- addr of element ||  ", node->number, node);
	// printf("%p <--- prev || %p <--- next \n", node->prev, node->next);
	if (data->counter != 1 && ft_check_duplicates(head, node, data) != EXIT_SUCCESS)
		return (data->err_msg = 4);
	// printf("%d <-- duplic check", ft_check_duplicates(head, node, data));
	return (EXIT_SUCCESS);
}

int	ft_create_node_from_string(t_struct *data, int i, int *j, t_list **head)
{
	int	k;

	k = 0;
	data->tmp = ft_split(data->argv[i], 32);
	if (data->tmp == NULL)
		return (data->err_msg = 2);
	while (data->tmp[k])
	{
		data->nbr = ft_atoi_ps(data->tmp[k], data);
		if (ft_strlen(data->tmp[k]) == ft_strlen(ft_itoa(data->nbr)))
		{
			if (nbr_in_range(data->nbr) != 0)
				return (data->err_msg = 3);
			if (ft_create_node(data, data->nbr, head) != 0)
				return (data->err_msg = 4);
			j++;
		}
		else
		{
			ft_free_arr(data->tmp);
			return (data->err_msg = 1);
		}
		k++;
	}
	ft_free_arr(data->tmp);
	return (EXIT_SUCCESS);
}

int	ft_create_list(t_struct *data, t_list **head)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (data->argv[i] || i == 1)
	{
		data->nbr = ft_atoi_ps(data->argv[i], data);
		if (ft_strlen(data->argv[i]) == ft_strlen(ft_itoa(data->nbr)))
		{
			if (nbr_in_range(ft_atoi_ps(data->argv[i], data)) != 0)
				return (ft_error(3));
			if (ft_create_node(data, data->nbr, head) != EXIT_SUCCESS)
				return (data->err_msg);
			j++;
		}
		else if (ft_strchr(data->argv[i], ' ') != NULL)
		{
			if (ft_create_node_from_string(data, i, &j, head) != EXIT_SUCCESS)
				return (data->err_msg);
		}
		else
			return (ft_error(1));
		i++;
	}
	return (EXIT_SUCCESS);
}











// ----------	----------	----------	----------	----------	----------	----------	----------
// printf("%d\n", data->nbr);
// data->int_arr[j] = ft_calloc(1, sizeof(int *));
// data->int_arr[j] = &data->nbr;




// if (ft_duplicates(data, &data->nbr) != 0)
// 	ft_error(4);