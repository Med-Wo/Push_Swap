/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:23:22 by mravily           #+#    #+#             */
/*   Updated: 2022/01/17 17:08:18 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}