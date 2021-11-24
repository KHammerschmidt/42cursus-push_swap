/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:21 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/24 11:38:58 by katharinaha      ###   ########.fr       */
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
	t_list	*tmp;

	tmp = *head;
	while (tmp->next != *head)
	{
		
	}
}

int	ft_error(int msg)
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
	ft_free_lst();
	system("leaks push_swap");
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
	// data->int_arr = ft_calloc(sizeof(int *), 1);		// malloc allokieren
	// data->list_nbrs = 0;
	// t_list	stack_a;
	// t_list	stack_b;
	// t_list	*list;
}
