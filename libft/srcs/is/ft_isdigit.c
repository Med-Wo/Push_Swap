/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:06:47 by mravily           #+#    #+#             */
/*   Updated: 2021/09/06 19:24:07 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (false);
	return (true);
}

bool	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '-')
			i++;
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
