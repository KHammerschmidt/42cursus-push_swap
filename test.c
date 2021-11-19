/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:19:39 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/19 18:12:33 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_error(int msg)
{
	if (msg == 1)
		write(1, "ERROR", 5);
	
	// ft_free_lst();
	exit(EXIT_FAILURE);
}

int	ft_atoi_push_swap(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if ((str[i + 1] == '-') || (str[i + 1] == '+'))
			return (0);
		else if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (i == 0)
		ft_error(1);
	return (result * sign);
}

int		ft_is_nbr(char *input)
{
	int	nbr;

	nbr = ft_atoi(input);
	if (nbr > INT_MIN && nbr < INT_MAX)
	{
		printf("%d     ", nbr);
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (!argc)
		write(1, "AAA", 3);
	while (argv[++i])
	{
		ft_is_nbr(argv[i]);
	}
	return (0);
}