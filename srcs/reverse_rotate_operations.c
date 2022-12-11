#include "../header/push_swap.h"

/* Shift down all elements of stack a by 1. The last element becomes the
first one. */
void	rra(t_list1 **head_a, int flag)
{
	t_list1	*last_element;
	t_list1	*prev_element;

	last_element = *head_a;
	prev_element = *head_a;
	while (last_element->next)
		last_element = last_element->next;
	while (prev_element->next != last_element)
		prev_element = prev_element->next;
	prev_element->next = NULL;
	last_element->next = *head_a;
	*head_a = last_element;
	if (flag == 1)
		write(1, "rra\n", 4);
}

/* Shift down all elements of stack b by 1. The last element becomes the
first one. */
void	rrb(t_list1 **head_b, int flag)
{
	t_list1	*last_element;
	t_list1	*prev_element;

	last_element = *head_b;
	prev_element = *head_b;
	while (last_element->next)
		last_element = last_element->next;
	while (prev_element->next != last_element)
		prev_element = prev_element->next;
	prev_element->next = NULL;
	last_element->next = *head_b;
	*head_b = last_element;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

/* rra and rrb at the same time */
void	rrr(t_list1 **head_a, t_list1 **head_b)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	write(1, "rrr\n", 4);
}
