/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:26:20 by mravily           #+#    #+#             */
/*   Updated: 2022/01/17 17:48:34 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_index(int key, int id, t_element **stack)
{
	t_element	*actual;

	actual = (*stack);
	while (actual->next != NULL)
	{
		if (key == actual->value)
		{
			actual->id = id;
			break ;
		}
		actual = actual->next;
	}
	if (key == actual->value)
		actual->id = id;
}

/* Add element of tab to the stack_a */
void	add_to_lst(char **tab, t_list **data)
{
	size_t	i;
	t_node	*tree;

	tree = NULL;
	(*data)->stack_a = ft_elem_new(0, tab[0]);
	add_node(&tree, ft_atoi(tab[0]));
	i = 1;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > (*data)->bigger)
			(*data)->bigger = ft_atoi(tab[i]);
		ft_lstadd_back(&(*data)->stack_a, ft_elem_new(i, tab[i]));
		add_node(&tree, ft_atoi(tab[i]));
		i++;
	}
	(*data)->size = i;
	through_tree(tree, &(*data)->stack_a);

	clear_tree(&tree);
}

/* Return len of the chain_list from the elmt */
int	ft_lst_len(t_element *elmt)
{
	t_element	*actual;
	size_t		i;

	if (elmt == NULL)
		return (0);
	actual = elmt;
	i = 0;
	while (actual)
	{
		actual = actual->next;
		i++;
	}
	return (i);
}

/* Return the second last of the chain_list */
t_element	*second_last_element(t_element *elmt, int len_lst)
{
	t_element	*actual;
	int			i;

	actual = elmt;
	if (elmt)
	{
		i = 0;
		while (i < len_lst - 2)
		{
			actual = actual->next;
			i++;
		}
	}
	return (actual);
}
