/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:19:39 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/22 15:52:44 by katharinaha      ###   ########.fr       */
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
	if (msg == 2)
		write(1, "STRING", 6);
	// ft_free_lst();
	exit(EXIT_FAILURE);
}

int	ft_atoi_push_swap(const char *str)
{
	int	i;
	int	sign;
	int	result;
	int	flag;

	i = 0;
	sign = 1;
	result = 0;
	flag = 0;
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
		flag++;
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (i == 0 || flag == 0)
	{
		ft_error(1);
		return(EXIT_FAILURE);
	}
	return (result * sign);
}

int		ft_is_nbr(char *input)
{
	int	nbr;

	nbr = ft_atoi_push_swap(input);
	if (nbr > INT_MIN && nbr < INT_MAX)
	{
		printf("%d     ", nbr);
		return (0);
	}
	else
		return (1);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	else
		return (NULL);
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (!argc)
		printf("%d\n", argc);
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' ') != NULL)
			ft_error(2);
		else
			ft_is_nbr(argv[i]);
	}
	return (0);
}