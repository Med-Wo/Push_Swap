/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:02:29 by mravily           #+#    #+#             */
/*   Updated: 2021/08/11 19:12:57 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_replace_front(char *s2, char **s1)
{
	char	*result;

	result = ft_strjoin(s2, *s1);
	if (*s1 != NULL)
		free(*s1);
	*s1 = result;
}

void	ft_str_replace_back(char **s1, char *s2)
{
	char	*result;

	result = ft_strjoin(*s1, s2);
	if (*s1 != NULL)
		free(*s1);
	*s1 = result;
}
