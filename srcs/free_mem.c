#include "../header/push_swap.h"

/* Frees every element of a list pointed to by the stack's head. */
void	ft_free_lst(t_list1 **stack_head)
{
	t_list1	*tmp;

	tmp = *stack_head;
	while (tmp)
	{
		stack_head = &(*stack_head)->next;
		free(tmp);
		tmp = *stack_head;
	}
}

/* Frees every element of an array. */
void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}
