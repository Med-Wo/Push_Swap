/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:31:30 by mravily           #+#    #+#             */
/*   Updated: 2021/12/26 16:26:48 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function to get the len of binary number */
int	get_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/* Function to get the largest element from an array */
int	get_max(t_element *stack)
{
	t_element	*actual;
	int			max;

	max = stack->id;
	while (stack->next != NULL)
	{
		if (actual->id > max)
			max = actual->id;
		actual = actual->next;
	}
	return (max);
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

void	sort_five(t_list **data, int size)
{
	int		i;

	i = 0;
	while (i < size - 3)
	{	
		if ((*data)->stack_a->id == 0 || (*data)->stack_a->id == 1)
		{
			push(&(*data)->stack_a, &(*data)->stack_b, "pb");
			i++;
		}
		rotate(&(*data)->stack_a, "ra");
	}
	sort_three(data);
	while ((*data)->stack_b)
		push(&(*data)->stack_b, &(*data)->stack_a, "pa");
	if ((*data)->stack_a->id != 0)
		swap(&(*data)->stack_a, "sa");
}
