#include "../header/push_swap.h"

/* Swap the first elements at the top of stack a. Do nothing if there is only
one or no elements. */
void	sa(t_list1 **head_a, int flag)
{
	int		tmp;

	if (!*head_a || !(*head_a)->next)
		return ;
	tmp = (*head_a)->number;
	(*head_a)->number = (*head_a)->next->number;
	(*head_a)->next->number = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

/* Swap the first 2 elements at the top of stack b. Do nothing if there is
only one or no elements. */
void	sb(t_list1 **head_b, int flag)
{
	int		tmp;

	if (!*head_b || !(*head_b)->next)
		return ;
	tmp = (*head_b)->number;
	(*head_b)->number = (*head_b)->next->number;
	(*head_b)->next->number = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

/* Swap sa and sb at the same time. */
void	ss(t_list1 **head_a, t_list1 **head_b)
{
	sa(head_a, 0);
	sb(head_b, 0);
	write(1, "ss\n", 3);
}
