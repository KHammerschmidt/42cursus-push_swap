#include "../header/push_swap.h"

/* Take the first element at the top of b and put it at the top of a. Do
nothing if stack b is empty. */
void	pa(t_list1 **head_a, t_list1 **head_b)
{
	t_list1	*element;

	if (*head_b == NULL)
		return ;
	element = *head_b;
	if (element->next == NULL)
		*head_b = NULL;
	else
		*head_b = element->next;
	ft_lstadd_front_push_swap(head_a, element);
	write(1, "pa\n", 3);
}

/* Take the first element of the top of a and put it at the top of b. Do
nothing if stack a is empty. */
void	pb(t_list1 **head_a, t_list1 **head_b)
{
	t_list1	*element;

	if (*head_a == NULL)
		return ;
	element = *head_a;
	if (element->next == NULL)
		*head_a = NULL;
	else
		*head_a = element->next;
	ft_lstadd_front_push_swap(head_b, element);
	write(1, "pb\n", 3);
}
