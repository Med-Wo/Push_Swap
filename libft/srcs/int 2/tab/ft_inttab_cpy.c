/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttab_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:28:18 by mravily           #+#    #+#             */
/*   Updated: 2021/09/02 13:27:17 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_inttab_cpy(int **dest, int **src)
{
	int	i;

	if (src == NULL)
		error_exit("", "Src is null in ft_inttab_cpy");
	if (dest == NULL)
		error_exit("", "Dest is null in ft_inttab_cpy");
	i = 0;
	while (src[i] != NULL)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = NULL;
}
