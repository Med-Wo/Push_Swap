/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:31:30 by mravily           #+#    #+#             */
/*   Updated: 2022/01/17 00:06:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **data)
{
	if (((*data)->stack_a->id > (*data)->stack_a->next->id
			&& (*data)->stack_a->next->id < (*data)->stack_a->next->next->id
			&& (*data)->stack_a->id < (*data)->stack_a->next->next->id)
		|| ((*data)->stack_a->id > (*data)->stack_a->next->id
			&& (*data)->stack_a->next->id > (*data)->stack_a->next->next->id
			&& (*data)->stack_a->id > (*data)->stack_a->next->next->id)
		|| ((*data)->stack_a->id < (*data)->stack_a->next->id
			&& (*data)->stack_a->next->id > (*data)->stack_a->next->next->id
			&& (*data)->stack_a->id < (*data)->stack_a->next->next->id))
		swap(&(*data)->stack_a, "sa");
	if ((*data)->stack_a->id > (*data)->stack_a->next->id
		&& (*data)->stack_a->next->id < (*data)->stack_a->next->next->id
		&& (*data)->stack_a->id > (*data)->stack_a->next->next->id)
		rotate(&(*data)->stack_a, "ra");
	else if ((*data)->stack_a->id < (*data)->stack_a->next->id
		&& (*data)->stack_a->next->id > (*data)->stack_a->next->next->id
		&& (*data)->stack_a->id > (*data)->stack_a->next->next->id)
		reverse_rotate(&(*data)->stack_a, "rra");
}

void	sort_four(t_list **data)
{
	int	index_min;
	int	min;

	min = get_min((*data)->stack_a);
	index_min = get_index((*data)->stack_a, min);
	if (index_min == 1)
		swap(&(*data)->stack_a, "sa");
	if (index_min > 1)
		while (index_min++ != 4)
			reverse_rotate(&(*data)->stack_a, "rra");
	if (is_sorted((*data)->stack_a))
		return ;
	push(&(*data)->stack_a, &(*data)->stack_b, "pb");
	sort_three(data);
	push(&(*data)->stack_b, &(*data)->stack_a, "pa");
}

void	sort_five(t_list **data)
{
	int	index_min;
	int	min;

	min = get_min((*data)->stack_a);
	index_min = get_index((*data)->stack_a, min);
	if (index_min == 1 || index_min == 2)
		while (index_min-- != 0)
			rotate(&(*data)->stack_a, "ra");
	else if (index_min > 2)
		while (index_min++ != 5)
			reverse_rotate(&(*data)->stack_a, "rra");
	if (is_sorted((*data)->stack_a))
		return ;
	push(&(*data)->stack_a, &(*data)->stack_b, "pb");
	sort_four(data);
	push(&(*data)->stack_b, &(*data)->stack_a, "pa");
	print_list("STACK_A", (*data)->stack_a);
}

void	radix_sort_binary(t_list **data)
{
	int	i;
	int	max_bits;
	int	size;

	max_bits = get_max_bits((*data)->bigger) + 1;
	i = 0;
	while (i < max_bits)
	{
		size = ft_lst_len((*data)->stack_a);
		while (size)
		{
		
			if (((*data)->stack_a->id >> i & 1) == 1)
				rotate(&(*data)->stack_a, "ra");
			else
				push(&(*data)->stack_a, &(*data)->stack_b, "pb");
			size--;
		}
		while ((*data)->stack_b)
			push(&(*data)->stack_b, &(*data)->stack_a, "pa");
		i++;
	}
}
