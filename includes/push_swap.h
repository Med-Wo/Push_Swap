/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:01:02 by mravily           #+#    #+#             */
/*   Updated: 2022/01/16 15:07:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# include "libft.h"

typedef struct s_element
{
	int					id;
	int					value;
	struct s_element	*next;
}						t_element;

typedef struct s_list
{
	t_element			*stack_a;
	t_element			*stack_b;
	int					bigger;
	int					size;
}				t_list;

/* Debug function */
void		print_list(char *title, t_element *actual);

/* Check functions */
bool		check_duplicate(char **av);
void		check_argument(char **tab, t_list **stacks);
bool		a_is_sorted(t_element *stack_a);
bool		is_sorted(t_element *stack_a);

/* Chain list function */
t_element	*ft_lstlast(t_element *actual);
t_element	*ft_elem_new(int id, char *value);
t_element	*second_last_element(t_element *elmt, int len_lst);
t_list		*init_list(void);
int			ft_lst_len(t_element *elmt);
void		ft_lstadd_back(t_element **list, t_element *new);
void		ft_lstadd_front(t_element **list, t_element *to_add);
void		create_chain_lst(char **argv, char **envp);
void		add_to_lst(char **tab, t_list **stacks);
void		free_list(t_list **data);

/* Actions functions */
void		sort_list(t_list **data);
void		swap(t_element **stack, char *action);
void		rotate(t_element **stack, char *action);
void		reverse_rotate(t_element **stack, char *action);
void		push(t_element **from_stack, t_element **to_stack, char *action);

/* Sort function */
void		sort_three(t_list **data);
void		sort_five(t_list **data, int size);
void		radix_sort_binary(t_list **data);

typedef struct s_node
{
	int				key;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

/* Binary tree function */
int			search_node(t_node *tree, int key);
void		add_node(t_node **tree, int key);
void		clear_tree(t_node **tree);
void		through_tree(t_node *tree, t_element **stack);
void		change_index(int key, int id, t_element **stack);
void		print_tree(t_node *tree);
void		print_reverse_tree(t_node *tree);

#endif