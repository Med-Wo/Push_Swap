/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:31:13 by mravily           #+#    #+#             */
/*   Updated: 2021/09/09 18:27:33 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/* Remove the first element to list */
void	ft_remove_element(t_list *list)
{
	t_element *tmp;
	t_element *next_tmp;

	tmp = list->first->next;
	free(list->first);
	next_tmp = list->first->next->next;
	list->first = tmp;
	list->first->next = next_tmp;
}

/* Push the first element of list_1 to list_2 */
void	push_list(t_list *list_1, t_list *list_2)
{
	ft_lstadd_front(list_2, list_1->first);
	ft_remove_element(list_1);
}

void	switch_list(t_list *list)
{
	ft_lstadd_front(list, list->first->next);
}