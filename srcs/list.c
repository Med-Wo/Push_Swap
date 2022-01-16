/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:54:48 by mravily           #+#    #+#             */
/*   Updated: 2022/01/16 15:23:19 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_elem_new(int id, char *value)
{
	t_element	*new;

	new = (t_element *)malloc(sizeof(t_element));
	if (!new)
		ft_putendl_fd("Error Malloc Element", 3);
	new->id = id;
	new->value = ft_atoi(value);
	new->next = NULL;
	return (new);
}

t_list	*init_list(void)
{
	t_list	*data;

	data = (t_list *)malloc(sizeof(t_list));
	if (!data)
		ft_putendl_fd("Error Malloc List", 3);
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->bigger = INT_MIN;
	data->size = -1;
	return (data);
}

t_element	*ft_lstlast(t_element *actual)
{
	if (actual == NULL)
	{
		ft_putendl("List not initialized with element");
		return (NULL);
	}
	while (actual->next != NULL)
		actual = actual->next;
	return (actual);
}

void	ft_lstadd_back(t_element **list, t_element *new)
{
	t_element	*last;

	last = ft_lstlast(*list);
	last->next = new;
}

void	ft_lstadd_front(t_element **list, t_element *to_add)
{
	t_element	*tmp;

	tmp = *list;
	to_add->next = tmp;
	*list = to_add;
}
