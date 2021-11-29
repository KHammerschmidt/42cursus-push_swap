/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:21 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/29 21:33:51 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_duplicates(t_struct *data, int *nbr)
// {
// 	int	l;
// 	int	temp;

// 	l = 0;
// 	temp = data->counter;
// 	while (temp != 0)
// 	{
// 		printf("%d\n", data->int_arr[l]);
// 		// printf("%d <---l\n %d <--- data->counter\n", l, data->counter);
// 		if (data->int_arr[l] == nbr)
// 			break;
// 		temp--;
// 		l++;
// 	}
// 	if (temp != 0)
// 	{
// 		printf("%d <---l\n %d <--- temp\n", l, temp);
// 		return(EXIT_FAILURE);
// 	}
// 	return(EXIT_SUCCESS);
// 	// while (data->int_arr[l] != nbr)
// 	// 	l++;
// 	// if ((data->counter == 0 && l == 0) || l == (data->counter - 1) || l == 1)
// 	// 	return (EXIT_SUCCESS);
// 	// return (EXIT_FAILURE);
// }

int		nbr_in_range(int nbr)
{
	if (nbr > INT_MIN && nbr < INT_MAX)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

void	ft_free_lst(t_list **head)
{
	// t_list	*current_node;
	// t_list	*next;

	// current_node = *head;
	// while (current_node->next != *head)
	// {
	// 	next = current_node->next;
	// 	free(current_node);
	// 	current_node = next;
	// }

	t_list	*node;
	t_list	*next;

	node = *head;
	while (node->next != *head)
	{
		next = node->next;
		free(node);
		node = NULL;
		node = next;
	}
	free(node);
	node = NULL;
	// printf("HERE I AM !\n");
	// system("leaks push_swap");
}

int	ft_is_nbr(char *str, t_struct *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			return (data->err_msg = 1);
	}
	return (0);
}

int	ft_error(int msg, t_list **head)
{
	if (msg == 0)
		ft_putstr_fd("Error: Invalid number of arguments", STDERR_FILENO);	// not sure about number of args needed
	if (msg == 1)
		ft_putstr_fd("Error: Arguments must be of type int\n", STDERR_FILENO);
	if (msg == 2)
		ft_putstr_fd("Error: Memory allocation failed\n", STDERR_FILENO);
	if (msg == 3)
		ft_putstr_fd("Error: Arguments are >INT_MAX/<INT_MIN\n", STDERR_FILENO);
	if (msg == 4)
		ft_putstr_fd("Error: Arguments hold duplicates which cannot be sorted\n", STDERR_FILENO);
	if (msg == 5)
		ft_putstr_fd("Error: Creating doubly linked list element was unsuccesful", STDERR_FILENO);
	ft_free_lst(head);
	return (msg);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

void	initiate(t_struct *data, int argc, char *argv[])
{
	data->argc = argc;
	data->argv = argv;
	data->counter = 0;
	data->tmp = NULL;
	data->nbr = 0;
	data->err_msg = 0;
	data->int_flag = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
}
