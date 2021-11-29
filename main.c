/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:54:49 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/29 20:22:29 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_struct	*data;
	t_list		*head;

	data = ft_calloc(1, sizeof(t_struct));
	if (!data)
		return (ft_error(1, &head));
	if (argc < 2)
		return (ft_error(data->err_msg, &head));
	head = NULL;
	initiate(data, argc, argv);
	if (ft_create_list(data, &head) != 0)
		return (ft_error(data->err_msg, &head));
	ft_print_node(&head, data);

	// ft_free_lst(&head);
	// system("leaks push_swap");
	return (EXIT_SUCCESS);
}
