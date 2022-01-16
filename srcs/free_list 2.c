/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:32:35 by mravily           #+#    #+#             */
/*   Updated: 2021/12/26 17:33:44 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_element(t_element **actual)
{
	t_element	*tmp;

	while (*actual)
	{
		(*actual)->id = -1;
		(*actual)->value = -1;
		tmp = (*actual)->next;
		free((*actual));
		(*actual) = tmp;
	}
}

void	free_list(t_list **data)
{
	t_list	*tmp_list;

	tmp_list = (*data);
	if (!data)
		return ;
	free_element(&tmp_list->stack_a);
	free_element(&tmp_list->stack_b);
	tmp_list->bigger = -1;
	tmp_list->size = -1;
	free(tmp_list);
	(*data) = NULL;
}
