
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../42cursus-Libft/header/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* Defining struct */
typedef struct s_list1
{
	int				number;
	int				index;
	struct s_list1	*next;
} t_list1;

int		main(int argc, char *argv[]);
int		push_swap(t_list1 **head_a, t_list1 **head_b);

/* Input handling and initialising stack a with a simply linked list. */
int		init_stack_a(char *argv[], t_list1 **head_a);
void	ft_get_indx(t_list1 *node, t_list1 **head_a);
int		error_handling(char *str, t_list1 **head_a);
int		ft_lstsize_push_swap(t_list1 *lst);

/* Util functions of printing steps and freeing memory space. */
void	ft_free_arr(char **arr);
void	ft_free_lst(t_list1 **stack_head);

/* Sorting functions */
int		is_sorted(t_list1 **head_a);
void	ft_sort_three(t_list1 **head_a);
void	ft_sort_five(t_list1 **head_a, t_list1 **head_b);
void	ft_sort_big(t_list1 **head_a, t_list1 **head_b);

/* Sorting helpers, e.g. finding a specific value and pushing it to the
other stacak. */
void	push_smallest(t_list1 **head_src, t_list1 **head_dst);
void	push_largest(t_list1 **head_a, t_list1 **head_b);
int		find_smallest(t_list1 **head_a);
int		find_largest(t_list1 **head);

/* Push_swap functions */
void	sa(t_list1 **head_a, int flag);
void	sb(t_list1 **head_b, int flag);
void	ss(t_list1 **head_a, t_list1 **head_b);
void	pa(t_list1 **head_a, t_list1 **head_b);
void	pb(t_list1 **head_a, t_list1 **head_b);
void	ra(t_list1 **head_a, int flag);
void	rb(t_list1 **head_b, int flag);
void	rr(t_list1 **head_a, t_list1 **head_b);
void	rra(t_list1 **head_a, int flag);
void	rrb(t_list1 **head_b, int flag);
void	rrr(t_list1 **head_a, t_list1 **head_b);


/* Adapted lst functions from libft */
t_list1	*ft_lstnew_push_swap(int content);
void	ft_lstadd_back_push_swap(t_list1 **lst, t_list1 *new);
t_list1	*ft_lstlast_push_swap(t_list1 *lst);
int		ft_lstsize_push_swap(t_list1 *lst);
void	ft_lstadd_front_push_swap(t_list1 **lst, t_list1 *new);

#endif