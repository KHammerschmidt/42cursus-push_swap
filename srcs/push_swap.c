#include "../header/push_swap.h"

/* Calls the respective sorting algorithm in relation to the number of
testcases. */
int	push_swap(t_list1 **head_a, t_list1 **head_b)
{
	int	len;

	len = ft_lstsize_push_swap(*head_a);
	if (len == 2)
		sa(head_a, 1);
	else if (len == 3)
		ft_sort_three(head_a);
	else if (len <= 5)
		ft_sort_five(head_a, head_b);
	else
		ft_sort_big(head_a, head_b);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list1	*head_a;
	t_list1	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (1);
	init_stack_a(argv, &head_a);
	if (is_sorted(&head_a) == 1)
	{
		ft_free_lst(&head_a);
		return (0);
	}
	push_swap(&head_a, &head_b);
	ft_free_lst(&head_a);
	return (0);
}
