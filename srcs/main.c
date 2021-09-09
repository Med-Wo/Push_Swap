/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 08:58:41 by mravily           #+#    #+#             */
/*   Updated: 2021/09/09 18:35:37 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fusion (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}
 
void tri_fusion (int *liste, int taille) {
    if (taille < 2) return;
    int milieu = taille / 2;
    tri_fusion(liste, milieu);
    tri_fusion(liste, taille - milieu);
    fusion(liste, taille, milieu);
}

bool	check_duplicate(char **av)
{
	int	i;
	int y;

	i = 1;
	y = 0;
	while(av[i] != NULL)
	{
		y = 1;
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

void	check_argument(char **av)
{
	int		i;
	long	test;

	i = 1;
	ft_print_str_tab("ARGV", av);
	while(av[i] != NULL)
	{
		if (ft_strlen(av[i]) == 0 || ft_strlen(av[i]) > 9)
			error_exit(NULL, "Arguments contains a wrong value");
		if (ft_strisdigit(av[i]) == false)
			error_exit(NULL, "Arguments not contains only digits or NULL value");
		test = ft_atol(av[i]);
		if (test < INT_MIN || test > INT_MAX)
			error_exit(NULL, "Arguments contains value superior of inferior to INT");
		i++;
	}
	if (check_duplicate(av) == true)
			error_exit(NULL, "Arguments contains duplicates");
}

/* Print the contains of the chain list */
void	print_list(t_list *list)
{
	t_element	*actual;

	actual = list->first;
	while (actual != NULL)
	{
		printf("id = [%zu] ~ ", actual->id);
		printf("value = [%d]\n", actual->value);
		actual = actual->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;

	check_argument(av);
	list_a = init_list(av);
	list_b = (t_list *)malloc(sizeof(t_list));
	list_b->first = ft_lstnew(0, NULL);
	print_list(list_a);
	puts("");
	push_list(list_a, list_b);
	print_list(list_a);
	return (EXIT_SUCCESS);
	(void)ac;
}