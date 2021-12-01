/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:54:49 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/01 12:45:43 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_struct	*data;
	t_list		*head;

	head = NULL;
	data = ft_calloc(1, sizeof(t_struct));
	if (!data)
		return (ft_error(1, &head));
	if (argc < 2)
	{
		data->err_msg = 2;
		return (ft_error(data->err_msg, &head));
	}
	initiate(data, argc, argv);
	if (ft_create_list(data, &head) != EXIT_SUCCESS)
		return (ft_error(data->err_msg, &head));
	ft_print_node(&head, data);
	data->stack_a = &head;
	data->stack_b = NULL;
	write(1,"\n", 1);
	sa(&head, data);
	ft_print_node(&head, data);
	// system("leaks push_swap");
	return (EXIT_SUCCESS);
}
