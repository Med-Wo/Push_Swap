/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:45:45 by mravily           #+#    #+#             */
/*   Updated: 2022/01/17 17:47:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function to get the len of binary number */
// int	get_max_bits(int max_num)
// {
// 	int	max_bits;

// 	max_bits = 0;
// 	while ((max_num >> max_bits) != 0)
	
// 		max_bits++;
// 	return (max_bits);
// }

int	get_max_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_bits = 0;
	max_num = size - 1;
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

int	get_index(t_element *stack, int id)
{
	int	index;

	index = 0;
	while (stack->id != id)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

int	get_min(t_element *stack)
{
	int	min;

	min = stack->id;
	while (stack)
	{
		if (stack->id < min)
			min = stack->id;
		stack = stack->next;
	}
	return (min);
}
