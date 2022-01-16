/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:36:02 by mravily           #+#    #+#             */
/*   Updated: 2022/01/16 14:52:21 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tab_len(void **tab)
{
	int	index;

	index = 0;
	if (!tab)
		return (index);
	while (tab[index] != NULL)
		index++;
	return (index);
}
