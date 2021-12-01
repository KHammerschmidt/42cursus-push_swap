/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:36:10 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/01 12:45:50 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_node(t_list **head, t_struct *data)
{
	t_list	*tmp_node;
	char	*content_list;

	tmp_node = *head;
	content_list = NULL;
	if (!data)
		printf("!data");
	while (tmp_node->next != NULL)
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
	write(1, " ", 1);
	free(content_list);
	content_list = NULL;
	return (EXIT_SUCCESS);
}

t_list	*ft_lstnew(int content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->number = content;
	element->next = NULL;
	return (element);
}

static int	ft_create_node(t_struct *data, int nbr, t_list **head)
{
	t_list	*node;
	t_list	*tmp_node;
	int		j;

	j = 0;
	tmp_node = *head;
	node = ft_lstnew(nbr);
	if (node == NULL)
		return (data->err_msg = 5);
	data->counter++;
	if (*head == NULL)
		*head = node;
	else
	{
		while (tmp_node->next != NULL)
			tmp_node = tmp_node->next;
		tmp_node->next = node;
	}
	// printf("%p <--- head  ||  ", head);
	// printf("%d <--- int of element || %p <--- addr of element ||  ", node->number, node);
	// printf("%p <--- next \n", node->next);
	if (ft_check_duplicates(head, node, data) != EXIT_SUCCESS)
		return (data->err_msg);
	return (EXIT_SUCCESS);
}

static int	ft_create_node_from_string(t_struct *data, int i, int *j, t_list **head)
{
	int	k;

	k = 0;
	data->tmp = ft_split(data->argv[i], 32);
	if (data->tmp == NULL)
		return (data->err_msg = 2);
	while (data->tmp[k])
	{
		if (ft_is_nbr(data->tmp[k], data) != 0)
		{
			ft_free_arr(data->tmp);
			return (data->err_msg = 1);
		}
		data->nbr = ft_atoi_ps(data->tmp[k], data, head);
		if (nbr_in_range(data->nbr, data) != 0)
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
		if (ft_strchr(data->argv[i], ' ') != NULL)
		{
			if (ft_create_node_from_string(data, i, &j, head) != EXIT_SUCCESS)
				return (data->err_msg);
		}
		else if (ft_is_nbr(data->argv[i], data) != 0)
			return (data->err_msg);
		else
		{
			data->nbr = ft_atoi_ps(data->argv[i], data, head);
			if (nbr_in_range(data->nbr, data) != 0)
				return (data->err_msg);
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

// static int	ft_create_node(t_struct *data, int nbr, t_list **head)
// {
// 	t_list	*node;
// 	t_list	*previous_node;
// 	int		j;

// 	j = 0;
// 	previous_node = *head;				//previous node points to wherever head is pointing to
// 	node = ft_lstnew(&nbr);				//add new element (malloc, nbr, point to NULL)
// 	if (node == NULL)
// 		return (data->err_msg = 5);
// 	data->counter++;
// 	// node = ft_calloc(1, sizeof(t_list));
// 	// if (node == NULL)
// 	// 	return (data->err_msg = 5);
// 	// node->number = nbr;
// 	// node->prev = NULL;
// 	// node->next = NULL;
// 	if (*head == NULL)
// 		*head = node;
// 	else												//add the
// 	{
// 		previous_node = ft_lstlast(*previous_node);		//returns the last element of the list
// 		previous_node->next = node;						//adds the last element

// 		// ft_lstadd_back(head, node);
// 		// node->next = *head;
// 		// (*head)->prev = node;
// 		if (previous_node->next == NULL)
// 			previous_node->next = node;
// 		else
// 		{
// 			while (previous_node->next != *head) // while (j++ != data->counter)
// 				previous_node = previous_node->next;
// 			previous_node->next = node;
// 		}
// 		node->prev = previous_node;
// 	}
// 	// printf("%p <--- root  ||  ", head);
// 	// printf("%d <--- int of element || %p <--- addr of element ||  ", node->number, node);
// 	// printf("%p <--- prev || %p <--- next \n", node->prev, node->next);
// 	// if (data->counter != 1 && ft_check_duplicates(head, node, data) != EXIT_SUCCESS)
// 	// 	return (data->err_msg = 4);
// 	if (ft_check_duplicates(head, node, data) != EXIT_SUCCESS)
// 		return (data->err_msg = 4);
// 	// printf("%d <-- duplic check", ft_check_duplicates(head, node, data));
// 	return (EXIT_SUCCESS);
// }