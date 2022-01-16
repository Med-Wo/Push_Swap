/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:34:37 by mravily           #+#    #+#             */
/*   Updated: 2021/08/26 17:31:25 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Realloue un tableau + 1, ajoute la chaine to_add au tableau et free l'ancien
*/

void	ft_add_to_tab(void *to_add, void ***tab)
{
	void	**tmp;

	tmp = NULL;
	if (ft_tab_len(*tab) > 0)
	{
		tmp = ft_tab_new(ft_tab_len(*tab));
		ft_tab_dup(tmp, *tab);
		ft_tab_free((char **)*tab);
		*tab = NULL;
		*tab = ft_tab_new(ft_tab_len(tmp) + 1);
	}
	else
	{
		tmp = *tab;
		*tab = ft_tab_new(ft_tab_len(tmp) + 1);
	}
	if (tmp != NULL)
	{
		ft_tab_dup(*tab, tmp);
		ft_tab_free((char **)tmp);
	}
	(*tab)[ft_tab_len(*tab)] = ft_strdup(to_add);
}
