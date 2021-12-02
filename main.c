/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:54:49 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/02 21:06:28 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
	{
		write(1, ERR_NR_ARGS, ft_strlen(ERR_NR_ARGS));
		return (EXIT_FAILURE);
	}
	init_stack_a(argv, &head_a);
	// ft_print_node(data->stack_a, data);
	// // data->stack_a = &head;
	// write(1,"\n", 1);
	// // sa(data);
	// ft_print_node(data->stack_a, data);
	// // system("leaks push_swap");
	return (EXIT_SUCCESS);
}
