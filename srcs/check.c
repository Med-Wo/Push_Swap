/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:08:58 by mravily           #+#    #+#             */
/*   Updated: 2021/12/26 16:34:39 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_duplicate(char **av)
{
	int	i;
	int	y;

	i = 0;
	while (av[i] != NULL)
	{
		y = 0;
		while (av[y] != NULL)
		{
			if (y != i)
				if (ft_strcmp(av[i], av[y]) == 0)
					return (true);
			y++;
		}
		i++;
	}
	return (false);
}

void	error_handle(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	check_argument(char **tab, t_list **data)
{
	int			i;
	long		test;

	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strlen(tab[i]) == 0 || ft_strlen(tab[i]) > 9)
			error_handle("Error\n");
		if (ft_strisdigit(tab[i]) == false)
			error_handle("Error\n");
		if (ft_strlen(tab[i]) > 10)
			error_handle("Error\n");
		test = ft_atol(tab[i]);
		if (test < INT_MIN || test > INT_MAX)
			error_handle("Error\n");
		i++;
	}
	if (check_duplicate(tab) == true)
		error_handle("Error\n");
	add_to_lst(tab, data);
}

bool	is_sorted(t_element *stack_a)
{
	t_element	*actual;
	t_element	*next;

	actual = stack_a;
	next = stack_a->next;
	while (actual->next)
	{
		if (actual->id > next->id)
			return (false);
		actual = actual->next;
		next = next->next;
	}
	return (true);
}

bool	a_is_sorted(t_element *stack_a)
{
	int		smaller;

	smaller = -1;
	while (stack_a->next != NULL)
	{
		if (smaller == -1)
			smaller = stack_a->value;
		else if (stack_a->value > smaller)
			smaller = stack_a->value;
		else
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}
