/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:36:10 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/29 21:41:09 by khammers         ###   ########.fr       */
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
		if (j == data->counter - 2)
			return (EXIT_SUCCESS);
		if (node->number == tmp_node->number)
		{
			printf("BLUB!\n");
			printf("%d %d\n", j, data->counter);
			return (data->err_msg = 4);
		}
		tmp_node = tmp_node->next;
		j++;
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
	// if (data->counter != 1 && ft_check_duplicates(head, node, data) != EXIT_SUCCESS)
	// 	return (data->err_msg = 4);
	if (ft_check_duplicates(head, node, data) != EXIT_SUCCESS)
		return (data->err_msg = 4);
	// printf("%d <-- duplic check", ft_check_duplicates(head, node, data));
	return (EXIT_SUCCESS);
}

int	ft_create_node_from_string(t_struct *data, int i, int *j, t_list **head)
{
	int	k;

	k = 0;
	data->tmp = ft_split(data->argv[i], 32);							//split and then while loop ft-isdigit
	if (data->tmp == NULL)
		return (data->err_msg = 2);
	while (data->tmp[k])
	{
		if (ft_is_nbr(data->tmp[k], data) != 0)							//if input is not a number
		{
			ft_free_arr(data->tmp);
			return (data->err_msg = 1);
		}
		data->nbr = ft_atoi_ps(data->tmp[k], data, head);
		if (nbr_in_range(data->nbr) != 0)
			return (data->err_msg = 3);
		if (ft_create_node(data, data->nbr, head) != 0)
			return (data->err_msg = 4);
		k++;
	}
	ft_free_arr(data->tmp);
	j++;
	return (EXIT_SUCCESS);
}

int	ft_create_list(t_struct *data, t_list **head)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (data->argv[i])
	{
		if (ft_strchr(data->argv[i], ' ') != NULL)									//if input is a string of numbers
		{
			if (ft_create_node_from_string(data, i, &j, head) != EXIT_SUCCESS)
				return (data->err_msg);
		}
		else if (ft_is_nbr(data->argv[i], data) != 0)								//if input is not a number
			return (data->err_msg);
		else																		//if input consists of numbers
		{
			if (nbr_in_range(ft_atoi_ps(data->argv[i], data, head)) != 0)
				return (ft_error(3, head));
			if (ft_create_node(data, data->nbr, head) != EXIT_SUCCESS)
				return (data->err_msg);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}











// ----------	----------	----------	----------	----------	----------	----------	----------
// printf("%d\n", data->nbr);
// data->int_arr[j] = ft_calloc(1, sizeof(int *));
// data->int_arr[j] = &data->nbr;


	// data->nbr = ft_atoi_ps(data->argv[i], data, head);
	// if (ft_strlen(data->argv[i]) == ft_strlen(ft_itoa(data->nbr)))
	// else if (ft_strchr(data->argv[i], ' ') != NULL)
	// {
	// 	if (ft_create_node_from_string(data, i, &j, head) != EXIT_SUCCESS)
	// 		return (data->err_msg);
	// }
	// else
	// 	return (ft_error(1, head));


	// if (ft_strlen(data->tmp[k]) == ft_strlen(ft_itoa(data->nbr)))
	// {
	// 	if (nbr_in_range(data->nbr) != 0)
	// 		return (data->err_msg = 3);
	// 	if (ft_create_node(data, data->nbr, head) != 0)
	// 		return (data->err_msg = 4);
	// 	j++;
	// }

// if (ft_duplicates(data, &data->nbr) != 0)
// 	ft_error(4);