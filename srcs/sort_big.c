#include "../header/push_swap.h"

/* Counts the number of bits of each number's index and saves the maximum. */
static int	count_bits(t_list1 **head_a)
{
	int		len;
	int		len_max;
	int		save;
	t_list1	*tmp;

	len = 0;
	len_max = 0;
	tmp = *head_a;
	while (tmp->next)
	{
		save = tmp->index;
		len = 0;
		while (save)
		{
			len++;
			save >>= 1;
			if (len > len_max)
				len_max = len;
		}
		tmp = tmp->next;
	}
	return (len_max);
}

/* Flag 1: Compares if the rightmost space of the index in binary is 0 or 1.
If 0, number is pushed to stack b, otherwise stack a rotates.
Flag 2: Checks if the next position of the numbers on stack b holds a
0 or 1. If 1, they are pushed back to stack a, otherwise they stay on stack
b and b rotates. */
static void	check_stack(t_list1 **head_a, t_list1 **head_b, int k, int flag)
{
	int	save;
	int	max_bits;

	max_bits = count_bits(head_a);
	if (flag == 1)
	{
		save = (*head_a)->index;
		if ((((save) >> k) & 1) == 0)
			pb(head_a, head_b);
		else
			ra(head_a, 1);
	}
	if (flag == 2)
	{
		save = (*head_b)->index;
		if ((((save) >> k) & 1) != 0 || k == max_bits)
			pa(head_a, head_b);
		else
			rb(head_b, 1);
	}
}

/* Sorting algorithm for numbers > 100. Every number's index is being
compared in binary in check_stack(). */
void	ft_sort_big(t_list1 **head_a, t_list1 **head_b)
{
	t_list1	*tmp;
	int		max_bits;
	int		j;
	int		k;

	k = 0;
	tmp = *head_a;
	max_bits = count_bits(head_a);
	while (k < max_bits)
	{
		j = ft_lstsize_push_swap(*head_a);
		while (j-- > 0 && is_sorted(head_a) == 0)
			check_stack(head_a, head_b, k, 1);
		k++;
		j = ft_lstsize_push_swap(*head_b);
		while (j-- != 0)
			check_stack(head_a, head_b, k, 2);
	}
}
