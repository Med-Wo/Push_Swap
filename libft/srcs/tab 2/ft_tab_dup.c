/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:13:24 by mravily           #+#    #+#             */
/*   Updated: 2021/08/13 10:27:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tab_dup(void **dst, void **src)
{
	int	index;

	index = 0;
	while (src[index] != NULL)
	{
		dst[index] = ft_strdup(src[index]);
		index++;
	}
}
