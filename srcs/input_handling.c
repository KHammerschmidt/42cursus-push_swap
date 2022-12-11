#include "../header/push_swap.h"

/* Checks if input holds any duplicate numbers. */
static int	check_dups(t_list1 **head_a, char *str)
{
	int		num;
	int		len;
	int		i;
	t_list1	*tmp_node;

	i = 0;
	len = ft_lstsize_push_swap(*head_a);
	if (len <= 1)
		return (-1);
	num = ft_atoi(str);
	tmp_node = *head_a;
	while (tmp_node)
	{
		if (tmp_node->number == num && i < len)
			return (-1);
		else
			tmp_node = tmp_node->next;
		i++;
	}
	return (0);
}

/* Checks if input is an int, consisting of only a sign (-/+)
and digits. */
static int	ft_isint(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[0] == '+'))
		{
			if (ft_isdigit(str[i + 1]) == 0)
				i++;
			else
				return (-1);
		}
		if (ft_isdigit(str[i]) == 0)
			i++;
		else
			return (-1);
	}
	return (0);
}

/* Checks if input is of type int or if any duplicates were detected. */
int	error_handling(char *str, t_list1 **head_a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isint(str) != 0
			|| (ft_atoi(str) == 0 && str[i] != (0 + '0'))
			|| check_dups(head_a, str) != 0)
		{
			free(str);
			ft_free_lst(head_a);
			write(1, "Error\n", 7);
			exit(1);
		}
		i++;
	}
	return (0);
}
