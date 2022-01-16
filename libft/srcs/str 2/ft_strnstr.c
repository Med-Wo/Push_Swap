/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:59:21 by mravily           #+#    #+#             */
/*   Updated: 2021/08/11 19:01:16 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *find, size_t len)
{
	size_t	i;
	char	*pstr;
	char	*pfind;

	if (*find == '\0')
	{
		return ((char *)str);
	}
	pstr = (char *)str;
	pfind = (char *)find;
	i = 0;
	while (pstr[i] != '\0' && i < (len - ft_strlen(pfind) + 1)
		&& ft_strlen(pfind) <= len)
	{
		if (ft_strncmp((pstr + i), pfind, ft_strlen(pfind)) == 0)
		{
			return (pstr + i);
		}
		i++;
	}
	return (NULL);
}
