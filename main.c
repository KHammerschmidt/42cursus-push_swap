/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:54:49 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/24 11:32:21 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_struct	*data;
	t_list		*head;

	data = ft_calloc(1, sizeof(t_struct));
	if (!data)
		return (ft_error(1));
	if (argc < 2)						//******pdf, special cases when 1 or 2 numbers******
		return (ft_error(data->err_msg));
	head = NULL;
    initiate(data, argc, argv);
	if (ft_create_list(data, &head) != 0)
		return (ft_error(data->err_msg));
	ft_print_node(&head, data);
	system("leaks push_swap");
	return (EXIT_SUCCESS);
}
