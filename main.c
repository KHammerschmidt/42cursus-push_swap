/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:07:39 by khammers          #+#    #+#             */
/*   Updated: 2021/11/12 16:05:44 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
}

// void	ft_error_msg(int msg, t_struct *data)
// {
// 	if (msg == 1)
// 		ft_putstr_fd("Error\nSome arguments aren't integers\n", STDERR_FILENO);
// 	if (msg == 2)
// 		ft_putstr_fd("Error\nSome arguments are bigger than an int\n", STDERR_FILENO);
// 	if (msg == 3)
// 		ft_putstr_fd("Error\nSome arguments are smaller than an int\n", STDERR_FILENO);
// 	if (msg == 4)
// 		ft_putstr_fd("Error\nThere are duplicates in your input, this cannot be sorted", STDERR_FILENO);
// 	// ft_free_arr(data->list_nbrs);
// 	exit(1);
// }

int	ft_error_msg_ints(char *input, t_struct *data)
{
	int	nbr;
	int	j;

	j = 0;
	nbr = ft_atoi(input);
	if (ft_isdigit(nbr) != 0)
		ft_putstr_fd("Error\nSome arguments aren't integers\n", STDERR_FILENO);		// ft_error_msg(1, data);
	if (nbr < -32767) 		//INT_MIN) //has to be defined
		ft_putstr_fd("Error\nSome arguments are bigger than an int\n", STDERR_FILENO);	// ft_error_msg(2, data);
	if (nbr > 32767) 		//INT_MIN) //has to be defined
		ft_putstr_fd("Error\nSome arguments are smaller than an int\n", STDERR_FILENO);	// ft_error_msg(3, data);
	while (data->list_nbrs[j])
	{
		if (nbr == data->list_nbrs[j])
		{
			ft_putstr_fd("Error\nThere are duplicates in your input, this cannot be sorted", STDERR_FILENO);	// ft_error_msg(4, data);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	return (nbr);
}

int	ft_count_digits(t_struct *data)
{
	int		i;
	int		j;
	int 	k;
	char	**tmp;
	int		nbr;

	i = 1;
	j = 0;
	k = 0;
	while (data->argv[i])
	{
		if (ft_strchr(data->argv[i], 34) == NULL)	//searching for "  (to see if arguments are put in as strings)
		{
			tmp = ft_split(data->argv[i], 32);	//split the string during spaces (return **char)
			k = 0;
			while(tmp[k])
			{
				// ft_create_node(data);
				nbr = ft_error_msg_ints(tmp[k], data);	//transform char to int (ft_atoi & error handling)
				data->list_nbrs[j] = nbr;	//saving the transformed char in list;
				k++;
			}
			ft_free_arr(tmp);
		}
		else
			data->list_nbrs[j] = ft_atoi(data->argv[i]);

		data->counter++;
		i++;
		j++;
	}
	return (0);
}

int	ft_create_stack(t_struct *data)
{
	t_stack stack_a;
	t_stak stack_b;


}

int	ft_handle_input(t_struct *data)
{
	ft_count_digits(data);
	ft_create_stack;

	// int		**stack;

	// char	**tmp;
	// int		nbr;

	// ft_create_stack;
	return (0);
}



void	ft_initialise(int argc, char *argv[], t_struct *data)
{
	data->argc = argc;
	data->argv = argv;
	data->counter = 0;
}

int	main(int argc, char *argv[])
{
	t_struct data;

	ft_initialise(argc, argv, &data);
	ft_handle_input(&data);
	ft_create_stack(&data);
	return (0);
}

