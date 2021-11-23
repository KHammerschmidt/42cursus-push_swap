/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:54:49 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/23 15:00:28 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_struct	*data;
	t_list		*head;

	data = ft_calloc(1, sizeof(t_struct));
	if (!data)
		return (EXIT_FAILURE);
	if (argc < 2)			//******pdf, special cases when 1 or 2 numbers******
		ft_error(0);
	head = NULL;
    initiate(data, argc, argv);
	if (ft_create_list(data, &head) != 0)
		return (ft_error(data->err_msg));
	else
		return (EXIT_SUCCESS);
}
