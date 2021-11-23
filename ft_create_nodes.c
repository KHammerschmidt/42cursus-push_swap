/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:36:10 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/23 15:03:47 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_create_node(t_struct *data, int nbr, t_list **head)
{
	t_list	*node;
	t_list	*last_node;

	last_node = *head;
	node = ft_calloc(1, sizeof(t_list));
	if (node == NULL)
		ft_error(5);
	node->number = nbr;
	node->prev = NULL;
	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
	{
		node->next = *head;		//connect the next pointer of current node to whatever head is pointing to (circular)
		(*head)->prev = node;	// to make it circular, newest element is the last element 
		if (last_node->next == NULL)
			last_node->next = node;	// next node is newly creates node
		else
		{
			while (last_node->next != *head)
				last_node = last_node->next;  
			last_node->next = node;
		}
		node->prev = last_node;		// previous node is the first element of the circle, e.g. to what head points to
	}
	printf("%p <--- root  ||  ", head);
	printf("%d <--- int of element || %p <--- addr of last_element ||  ", node->number, node);
	printf("%p <--- prev || %p <--- next \n", node->prev, node->next);
	data->counter++;
	return (EXIT_SUCCESS);
}

void	ft_create_node_from_string(t_struct *data, int i, int *j, t_list **head)
{
	int	k;

	k = 0;
	data->tmp = ft_split(data->argv[i], 32);
	if (data->tmp == NULL)
		ft_error(2);
	while (data->tmp[k])
	{
		data->nbr = ft_atoi_ps(data->tmp[k], data);
		if (ft_strlen(data->tmp[k]) == ft_strlen(ft_itoa(data->nbr)))
		{
			if (nbr_in_range(data->nbr) != 0)
				ft_error(3);
			ft_create_node(data, data->nbr, head);
			j++;
		}
		else
		{
			ft_free_arr(data->tmp);
			ft_error(1);
		}
		k++;
	}
	ft_free_arr(data->tmp);
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
				ft_error(3);
			ft_create_node(data, data->nbr, head);
			j++;
		}
		else if (ft_strchr(data->argv[i], ' ') != NULL)
			ft_create_node_from_string(data, i, &j, head);
		else
			ft_error(1);
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