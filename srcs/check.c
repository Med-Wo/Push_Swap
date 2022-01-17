/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:08:58 by mravily           #+#    #+#             */
/*   Updated: 2022/01/17 15:52:02 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if value is not duplicate */
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

/* Display error, free data and exit the programm with EXIT_FAILURE code */
void	error_handle(char *error, char **tab, t_list **data)
{
	ft_putstr_fd(error, 2);
	ft_tab_free(tab);
	(*data)->bigger = -1;
	(*data)->size = -1;
	free(*data);
	data = NULL;
	exit(EXIT_FAILURE);
}

/* Check if the arguments are valid */
void	check_argument(char **tab, t_list **data)
{
	int			i;
	long		test;

	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strlen(tab[i]) == 0 || ft_strlen(tab[i]) > 11)
			error_handle("Error\n", tab, data);
		if (ft_strisdigit(tab[i]) == false)
			error_handle("Error\n", tab, data);
		test = ft_atol(tab[i]);
		if (test < INT_MIN || test > INT_MAX)
			error_handle("Error\n", tab, data);
		i++;
	}
	if (check_duplicate(tab) == true)
		error_handle("Error\n", tab, data);
	add_to_lst(tab, data);
	ft_tab_free(tab);
}

/* Check if the stack is already sorted */
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
