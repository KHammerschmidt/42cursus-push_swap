/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammers <khammers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:43:21 by khammers          #+#    #+#             */
/*   Updated: 2021/12/15 09:50:16 by khammers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_atoi() function converts the initial portion of the string pointed
** to by 'str' to int representation.
**
** (1) While string consists of whitespaces or non-printable characters
** loop through string.
** (2) While '-' or '+' occur increment counter, if there are more than one
** sign return (0), if sign is negative, set it to -1.
** (3) While string consists of a number (0 to 9), convert each character
** to int representation ( * 10 + value of string - '0').
** (4) Return int variable multiplied by its sign.
*/

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if ((str[i + 1] == '-') || (str[i + 1] == '+'))
			return (0);
		sign = sign * (-1);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result * sign < -2147483648)
		return (0);
	if (result * sign > 2147483647)
		return (0);
	return (result * sign);
}
