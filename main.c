/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:54:49 by katharinaha       #+#    #+#             */
/*   Updated: 2021/12/03 13:53:19 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	ft_print_node(&head_a);
	sa(&head_a);
	ft_print_node(&head_a);
	// system("leaks push_swap");
	return (EXIT_SUCCESS);
}
