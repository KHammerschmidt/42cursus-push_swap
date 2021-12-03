/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:36:10 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/03 13:43:17 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_node(t_list **head_a)
{
	t_list	*tmp_node;
	char	*content_list;

	tmp_node = *head_a;
	content_list = NULL;
	while (tmp_node)
	{
		content_list = ft_itoa(tmp_node->number);
		write(1, content_list, ft_strlen(content_list));
		write(1, " | ", 3);
		tmp_node = tmp_node->next;
		free(content_list);
		content_list = NULL;
	}
	return (0);
}

int	error_handling(char **str, int j, t_list **head_a)
{
	while (str[j])
	{
		if (ft_isint(str[j]) != 0 || ft_isrange(ft_atoi(str[j]) != 0))
		{
			ft_free_arr(str);
			ft_free_lst(head_a);
			ft_error(2);
		}
		if (check_dups(head_a, ft_atoi(str[j])) != 0)
		{
			ft_free_arr(str);
			ft_free_lst(head_a);
			ft_error(4);
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

// static int	add_element(t_list **head_a, int nbr, int *stack_len)
// {
// 	t_list	*node;

// 	node = ft_lstnew(nbr);
// 	if (*head_a == NULL)
// 		*head_a = node;
// 	else
// 		ft_lstadd_back(&head_a, node);
// 	// printf("%p <--- head_a  ||  ", head_a);
// 	// printf("%d <--- int of element || %p <--- addr of element ||  ", node->number, node);
// 	// printf("%p <--- next \n", node->next);
// 	stack_len++;
// }

			// printf("%p <--- head_a  ||  ", head_a);
			// printf("%d <--- int of element || %p <--- addr of element ||  ", node->number, node);
			// printf("%p <--- next \n", node->next);




// int	init_stack_a(char *argv[], t_list **head_a)
// {
// 	int		i;
// 	int		j;
// 	int		stack_len;

// 	i = 1;
// 	j = 0;
// 	stack_len = 0;
// 	while (argv[i])
// 	{

// 		if (ft_strchr(argv[i], ' ') != NULL)
// 			create_lst_string(argv[i], &j, &head_a, &stack_len);
// 		else
// 		{
// 			ft_isint(argv[i]);
// 			nbr = ft_atoi(argv[i]);
// 			ft_isrange(nbr);
// 			add_element(&head_a, nbr, &stack_len);
// 			if (check_dups(&head_a) != 0)
// 				ft_error();
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }



// ----------	----------	----------	----------	----------	----------	----------	----------



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



	// while (str[k])
// 	{
// 		if (ft_is_nbr(data->tmp[k], data) != 0)
// 		{
// 			ft_free_arr(data->tmp);
// 			return (data->err_msg = 1);
// 		}
// 		data->nbr = ft_atoi_ps(data->tmp[k], data);
// 		if (nbr_in_range(data->nbr, data) != 0)
// 			return (data->err_msg = 3);
// 		if (ft_create_node(data, data->nbr) != 0)
// 			return (data->err_msg = 4);
// 		k++;
// 	}
// 	ft_free_arr(data->tmp);
// 	j++;
// 	return (EXIT_SUCCESS);
// }





// static int	ft_create_node(t_list **head, int nbr, int stack_len)
// {
// 	t_list	*node;
// 	t_list	*tmp_node;
// 	int		j;

// 	j = 0;

// 	// tmp_node = *data->stack_a;
// 	node = ft_lstnew(nbr);
// 	if (node == NULL)
// 		ft_error(5);

// 	if (*data->stack_a == NULL)
// 		*data->stack_a = node;
// 	else
// 	{
// 		while (tmp_node->next != NULL)
// 			tmp_node = tmp_node->next;
// 		tmp_node->next = node;
// 	}
// 	if (ft_check_duplicates(data->stack_a, node, data) != EXIT_SUCCESS)
// 		return (data->err_msg);
// 	return (EXIT_SUCCESS);
// }




	// content_list = ft_itoa(tmp_node->number);
	// write(1, content_list, ft_strlen(content_list));
	// write(1, " ", 1);
	// free(content_list);
	// content_list = NULL;