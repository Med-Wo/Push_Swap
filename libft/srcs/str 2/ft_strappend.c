/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:36:40 by mravily           #+#    #+#             */
/*   Updated: 2021/08/17 14:30:15 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
* Concatenates 2 strings into a new string
* don't forget to free the new string after using it
*/
char	*ft_strappend(char *s1, char *s2)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	s1_len;
	unsigned int	s2_len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(s1_len + s2_len + 1);
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
