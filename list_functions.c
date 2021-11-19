/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:47:18 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/19 16:44:14 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Prototype: t_list	*ft_lstnew(void *content):
**
** Allocates with malloc and returns a new element. The variable content is
** initialized with the value of the parameter content. The variable next is
** initialized to NULL. The new element is returned.
**
** (1) we assign memory space for the new element with the size of our list
** t_list. If the allocation failed we return 0.
** (2) the content of the element is initatialised with the value of the
** parameter,
** (3) the pointer to the next element is set to NULL, indicating it's the
** end of the list.
** (4) the new element is returned.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (element == NULL)
		return (EXIT_FAILURE);
	element->content = content;
	element->next = NULL;
	element->previous = NULL;
	return (element);
}

/*
** Protoype: void	ft_lstadd_back(t_list **lst, t_list *new):
**
** Adds the element 'new' at the end of the list. **lst: address of a pointer
** to the first link of a list. *new: the address of a pointer to the first
** element to be added to the list.
**
** (1) if any parameter is empty return nothing.
** (2) if the element '*lst' is empty, *lst points to the 'new' element,
** adding it to the list.
** (3) else: the pointer to the last element of '*lst' is saved in t_list 'temp'
** by calling ft_lstlast()
** (4) temp's pointer to the next element is set to the new list '*new' to add
** it to the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}

/*
** Prototype: void	ft_lstadd_front(t_list **lst, t_list *new);
**
** Adds elemenet new at the beginning of the list. **lst: address of a pointer
** to the first link of a list. *new: address of a pointer to the element to be
** added to the list.
**
** (1) if any parameter list is empty return nothing.
** (2) the pointer to the next element of 'new' (new->next) points to the
** previous first element of '*lst'
** (3) pointer to the first link of a list '*lst' then points to the 'new'
** element which has been added to the front of the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	if (data->counter == 0)
		new->previous = NULL;
	// new->previous = 
	*lst = new;
}

/*
** Prototype: void	ft_lstclear(t_list **lst, void (*del)(void *)):
**
** Deletes and frees the given element and every successor of that element,
** using the function 'del' and free(3). Finally, the pointer to the list must
** be set to NULL.
**
** (1) if any paramter is empty return nothing;
** (2) while lst & *lst are not at the end of the list yet: the pointer to
** the next element of lst (*lst->next) is saved in 'temp',
** (3) the function ft_lstdelone() is applied to the content of *lst and
** the function 'del' passed on.
** (4) to iterate through the string '*lst' points to 'lst->next' which
** was saved in temp;
** (5) when the while loop ends *lst is set to NULL to indicate the end
** of the list.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst || !lst || !*del)
		return ;
	while (lst && *lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

/*
** Prototype: int	ft_lstsize(t_list *lst);
**
** Counts the number of elements in a list.
**
** (1) while we are not at the end of the list yet: we iterate through the
** list by assigning lst the pointer to the next element.
** (2) at the same time whenever doing so, we increment the length.
** (3) we return the final length of the list. 
*/
int	ft_lstsize(t_list *lst)
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

/*
** Prototype: void	ft_lstdelone(t_list *lst, void (*del)(void *));
**
** Takes as a parameter an element and frees the memory of the element's
** content using the function 'del' given as a parameter and free the element.
** The memory of 'next' must not be freed.
**
** (1) if any parameter is empty return nothing;
** (2) function del is applied to the content of the element lst
** (lst->content) and the element freed afterwards.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}

/*
** Protoype: void	ft_lstiter(t_list *lst, void (*f)(void *)):
**
** Iterates the list 'lst' and applies the function 'f' to the content of each
** element.
**
** (1) if any parameter if empty return nothing;
** (2) while we are not at the end of the list: function f is applied to the
** content of element
** (3) and it is iterated through the list by assigning lst to the pointer to
** the next element. 
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
** Prototype: t_list	*ft_lstlast(t_list *lst);
**
** Returns the last element of the list.
**
** (1) if the list is empty return NULL;
** (2) while we are not at the end of the list: we iterate through the list
** by assigning lst the pointer to the next element;
** (3) if the next element is the last one (lst->next = NULL) we return this
** element, alias the last element of the last. 
*/
t_list	*ft_lstlast(t_list *lst)
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
