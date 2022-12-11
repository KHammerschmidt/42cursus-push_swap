#include "../header/push_swap.h"

/* Shift up all elements of stack a by 1. The first element becomes the last
one. */
void	ra(t_list1 **head_a, int flag)
{
	t_list1	*last_element;
	t_list1	*tmp;

	if (*head_a == NULL)
		return ;
	last_element = *head_a;
	tmp = *head_a;
	while (last_element->next)
		last_element = last_element->next;
	last_element->next = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
}

/* Shift up all elements of stack b by 1. The first element becomes the
last one. */
void	rb(t_list1 **head_b, int flag)
{
	t_list1	*last_element;
	t_list1	*tmp;

	if (*head_b == NULL)
		return ;
	last_element = *head_b;
	tmp = *head_b;
	while (last_element->next)
		last_element = last_element->next;
	last_element->next = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = NULL;
	if (flag == 1)
		write(1, "rb\n", 3);
}

/* ra and rb at the same time. */
void	rr(t_list1 **head_a, t_list1 **head_b)
{
	ra(head_a, 0);
	rb(head_b, 0);
	write(1, "rr\n", 3);
}
