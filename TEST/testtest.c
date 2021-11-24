/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:18:14 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/23 20:25:10 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "test.h"

int	ft_error(int msg)
{
	if (msg == 0)
		write(1, "0", 1);
		// ft_putstr_fd("Error: Invalid number of arguments", STDERR_FILENO);	// not sure about number of args needed
	if (msg == 1)
		write(1, "1", 1);
		// ft_putstr_fd("Error: Arguments must be of type int\n", STDERR_FILENO);
	if (msg == 2)
		write(1, "2", 1);
		// ft_putstr_fd("Error: ft_split failed\n", STDERR_FILENO);	
	if (msg == 3)
		write(1, "3", 1);
		// ft_putstr_fd("Error: Arguments are >INT_MAX/<INT_MIN\n", STDERR_FILENO);
	if (msg == 4)
		write(1, "4", 1);
		// ft_putstr_fd("Error: Arguments hold duplicates which cannot be sorted\n", STDERR_FILENO);
	if (msg == 5)
		write(1, "5", 1);
		// ft_putstr_fd("Error: Creating doubly linked list element was unsuccesful", STDERR_FILENO);
	// ft_free_lst();
	// ft_free_arr();
	return (msg);
}

int	ft_test(int number)
{
	if (number > 0)
		return (data->msg = 2);
	return (0);
}
int	main(void)
{
	t_struct *data;

	data.msg = 0;
	int	number;

	number = 300;
	if (ft_test(number) != 0)
		return (ft_error(data.msg));
		// write(1, "ERROR", 5);
	return (0);
}