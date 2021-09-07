/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:06:40 by mravily           #+#    #+#             */
/*   Updated: 2021/08/11 18:48:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isnum(int c)
{
	if ((c < '0' || c > '9') && c != '-' && c != '+')
		return (false);
	return (true);
}

bool	ft_strisnum(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isnum(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
