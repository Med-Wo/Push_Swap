/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:06:55 by mravily           #+#    #+#             */
/*   Updated: 2021/08/11 18:47:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (true);
	return (false);
}

bool	ft_strisascii(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isascii(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
