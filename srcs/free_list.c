/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:32:35 by mravily           #+#    #+#             */
/*   Updated: 2022/01/16 15:39:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free the stack */
void	free_element(t_element **actual)
{
	t_element	*tmp;

	while (*actual)
	{
		(*actual)->id = -1;
		(*actual)->value = -1;
		tmp = (*actual)->next;
		free(*actual);
		(*actual) = NULL;
		(*actual) = tmp;
	}
}

/* Free list */
void	free_list(t_list **data)
{
	if (!data)
		return ;
	free_element(&(*data)->stack_a);
	free_element(&(*data)->stack_b);
	(*data)->bigger = -1;
	(*data)->size = -1;
	free(*data);
	data = NULL;
}
