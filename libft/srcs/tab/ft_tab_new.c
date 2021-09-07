/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:35:32 by mravily           #+#    #+#             */
/*   Updated: 2021/08/11 18:49:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Create and allocate a new tab
* Don't forget to free tab after use it
*/
void	**ft_tab_new(int size)
{
	void	**result;
	int		index;

	result = (void **)malloc(sizeof(void *) * (size + 1));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		result[index] = NULL;
		index++;
	}
	result[index] = NULL;
	return (result);
}
