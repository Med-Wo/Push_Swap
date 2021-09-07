/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:54:48 by mravily           #+#    #+#             */
/*   Updated: 2021/09/06 20:15:54 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_lstnew(void)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof(t_element));
	new->id = 
	new->next = NULL;
	return (new);
}

t_list	*init_list(char **tab)
{
	t_list		*list;
	int i;

	list = (t_list *)malloc(sizeof(t_list));
	list->first = ft_lstnew();
	i = 1;
	while (tab[i])
	{
		
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
