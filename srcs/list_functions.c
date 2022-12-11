#include "../header/push_swap.h"

/* Behaves like ft_lstnew but initialises an index for every element.*/
t_list1	*ft_lstnew_push_swap(int content)
{
	t_list1	*element;

	element = (t_list1 *)malloc(sizeof(t_list1));
	if (element == NULL)
		return (0);
	element->number = content;
	element->index = 0;
	element->next = NULL;
	return (element);
}

/* Adds the element 'new' at the end of the list. */
void	ft_lstadd_back_push_swap(t_list1 **lst, t_list1 *new)
{
	t_list1	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast_push_swap(*lst);
		temp->next = new;
	}
}

t_list1	*ft_lstlast_push_swap(t_list1 *lst)
{
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize_push_swap(t_list1 *lst)
{
	int	length;

	length = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		length++;
	}
	return (length);
}

void	ft_lstadd_front_push_swap(t_list1 **lst, t_list1 *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}