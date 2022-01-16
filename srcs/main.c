/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 08:58:41 by mravily           #+#    #+#             */
/*   Updated: 2022/01/16 23:44:13 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Split space fill in argument and add to a new tab*/
char	**split_argument(char **av)
{
	char	**tab;
	char	**result;
	size_t	i;
	int		y;

	tab = NULL;
	result = NULL;
	i = 1;
	while (av[i])
	{
		if (ft_strcchr(av[i], ' '))
		{
			tab = ft_split(av[i], ' ');
			y = -1;
			while (tab[++y])
				ft_add_to_tab((void **)tab[y], (void ***)&result);
			ft_tab_free(tab);
		}
		else
			ft_add_to_tab((void **)av[i], (void ***)&result);
		i++;
	}
	return (result);
}

/* Print binary value */
void	print_binary(int n, int n_bit_to_display)
{
	unsigned int	bit;
	unsigned int	mask;
	int				i;

	bit = 0;
	mask = 1;
	i = 0;
	while (i < n_bit_to_display)
	{
		bit = (n & mask) >> i;
		ft_printf("%d", bit);
		mask <<= 1;
		i++;
	}
	ft_putstr("\n");
}

/* Print the contains of the chain list */
void	print_list(char *title, t_element *actual)
{
	ft_putendl(title);
	while (actual != NULL)
	{
		ft_printf("id = [%d] ~ ", actual->id);
		ft_printf("value = [%d] ~ binary = ", actual->value);
		//print_binary(actual->value, 3);
		actual = actual->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*data;

	if (ac == 1)
	{
		ft_putstr_fd("Error\n", 3);
		return (EXIT_FAILURE);
	}
	data = init_list();
	check_argument(split_argument(av), &data);
	sort_list(&data);
	free_list(&data);
	return (EXIT_SUCCESS);
}
