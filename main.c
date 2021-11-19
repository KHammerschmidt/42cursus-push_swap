/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katharinahammerschmidt <katharinahammer    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:15:30 by katharinaha       #+#    #+#             */
/*   Updated: 2021/11/19 17:19:32 by katharinaha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_node(t_struct *data, int content, t_list **head)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (EXIT_FAILURE);
	node->content = content;
	node->previous = NULL;
	node->next = NULL;
	if (*head == NULL)
		*head = node;
	else
	{

	}
}

int	ft_count_nodes(t_struct *data, t_list *list)
{
	int		i;
	int		j;
	int 	k;
	char	**tmp;
	int		nbr;

	i = 1;
	j = 0;
	k = 0;
	while (data->argv[i])
	{
		if (ft_is_nbr(ft_atoi(data->argv[i])) != 0)			// transform input to int format (not sure???)
		{

		}
		else
			ft_create_node(data, data->argv[i], &head);


		if (ft_isdigit(data->argv[i] != 0)					// test if input is a number
		{	
			tmp = ft_split(data->argv[i], 32);				//split the string during spaces (32) (return **char)
			k = 0;
			while (ft_isdigit(tmp[k]) == 0)
				k++;
			if (tmp[k] == NULL)
				ft_error(1);
			else
			{

			}
			if (ft_strchr(tmp[k] != 0))
				ft_error(1);
			while (tmp[k])
				while(tmp[k] && (ft_isdigit(tmp[k]) == 0))
				{
					ft_create_node(data, tmp[k], &head);
					element = ft_lstnew(tmp[k]);			// creates a new element;
					// ft_lstadd_back()	// adds new element to the end of the list;
					// ft_create_node(data);
					nbr = ft_error_msg_ints(tmp[k], data);	//transform char to int (ft_atoi & error handling)
					data->list_nbrs[j] = nbr;	//saving the transformed char in list;
					k++;
				}
				ft_free_arr(tmp);
			}
			else
				ft_error_msg_ints(1);
			
		}
		else
			ft_create_node(data, data->argv[i], &head);
			// data->list_nbrs[j] = ft_atoi(data->argv[i]);
		data->counter++;
		i++;
		j++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
    t_struct	*data;
	t_list		*list;

	list = NULL;
    initiate(data, argc, argv);
	ft_count_nodes(data, &list);
    // ft_create_lists(&data);
    // 1) ft_handle_input   2) count argcs  3) create lists


	return (EXIT_SUCCESS);
}