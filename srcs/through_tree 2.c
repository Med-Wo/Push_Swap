/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   through_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:19:59 by mravily           #+#    #+#             */
/*   Updated: 2021/12/26 15:31:04 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	through_tree(t_node *tree, t_element **stack)
{
	static int	i = 0;

	if (!tree)
		return ;
	if (tree->left)
		through_tree(tree->left, stack);
	change_index(tree->key, i++, stack);
	if (tree->right)
		through_tree(tree->right, stack);
}

int	search_node(t_node *tree, int key)
{
	while (tree)
	{
		if (key == tree->key)
			return (1);
		if (key > tree->key)
			tree = tree->right;
		else
			tree = tree->left;
	}
	return (0);
}

void	print_tree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		print_tree(tree->left);
	ft_printf("Cle = %d\n", tree->key);
	if (tree->right)
		print_tree(tree->right);
}

void	print_reverse_tree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->right)
		print_reverse_tree(tree->right);
	ft_printf("Cle = %d\n", tree->key);
	if (tree->left)
		print_reverse_tree(tree->left);
}
