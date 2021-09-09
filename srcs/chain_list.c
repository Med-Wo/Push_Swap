/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:54:48 by mravily           #+#    #+#             */
/*   Updated: 2021/09/09 18:09:40 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_lstnew(int id, char *value)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof(t_element));
	new->id = id;
	new->value = ft_atoi(value);
	new->next = NULL;
	return (new);
}

t_list	*init_list(char **tab)
{
	t_list		*list;
	t_element	*element;

	int i;
	size_t 	y;

	list = (t_list *)malloc(sizeof(t_list));
	list->first = ft_lstnew(0, tab[1]);
	element = list->first;
	y = 1;
	i = 2;
	while (tab[i] != NULL)
	{
		element->next = ft_lstnew(y++, tab[i++]);
		element = element->next;
	}
	return (list);
}

t_element	*ft_lstlast(t_list *lst)
{
	t_element	*actual;

	actual = lst->first;
	if (lst == NULL)
		return (NULL);
	if (lst->first == NULL)
		ft_putendl("List not initialized with element");
	while (actual && actual->next)
		actual = actual->next;
	return (actual);
}

void	ft_lstadd_back(t_list *lst, t_element *new)
{
	t_element	*tmp;

	tmp = ft_lstlast(lst);
	tmp->next = new;
}

void	ft_lstadd_front(t_list *list, t_element *to_add)
{
	t_element *tmp;
	t_element *next_tmp;

	tmp = list->first;
	next_tmp = to_add->next;
	list->first = to_add;
	list->first->next = tmp;
	list->first->next->next = next_tmp;
}