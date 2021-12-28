/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:06:47 by mravily           #+#    #+#             */
/*   Updated: 2021/12/25 17:20:01 by mravily          ###   ########.fr       */
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
	if (str[0] == '-')
			i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == false && str[i] != '\0')
			return (false);
		i++;
	}
	return (true);
}
