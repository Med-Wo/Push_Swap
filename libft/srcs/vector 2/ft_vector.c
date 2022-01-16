/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:43:31 by mravily           #+#    #+#             */
/*   Updated: 2021/08/11 18:59:03 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector2	create_vector2(int p_x, int p_y)
{
	t_vector2	result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}

t_vector2	*malloc_vector2(int p_x, int p_y)
{
	t_vector2	*result;

	result = (t_vector2 *)malloc(sizeof(t_vector2));
	if (result == NULL)
		error_exit("", "Can't malloc a t_vector2");
	*result = create_vector2(p_x, p_y);
	return (result);
}

void	swap_t_vector2(t_vector2 *a, t_vector2 *b)
{
	ft_swap_int(&(a->x), &(b->x));
	ft_swap_int(&(a->y), &(b->y));
}

bool	is_t_vector2_equal(t_vector2 a, t_vector2 b)
{
	if (a.x == b.x && a.y == b.y)
		return (true);
	else
		return (false);
}

float	distance_vector2(t_vector2 a, t_vector2 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}
