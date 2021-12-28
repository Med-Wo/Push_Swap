/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:02:45 by mravily           #+#    #+#             */
/*   Updated: 2021/12/26 16:55:48 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(int key)
{
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	elem->key = key;
	elem->left = NULL;
	elem->right = NULL;
	return (elem);
}

void	place_node(int key, t_node **tmp_node, t_node **tmp_tree, t_node *elem)
{
	(*tmp_node) = (*tmp_tree);
	if (key > (*tmp_tree)->key)
	{
		(*tmp_tree) = (*tmp_tree)->right;
		if (!(*tmp_tree))
			(*tmp_node)->right = elem;
	}
	else
	{
		(*tmp_tree) = (*tmp_tree)->left;
		if (!(*tmp_tree))
			(*tmp_node)->left = elem;
	}
}

void	add_node(t_node **tree, int key)
{
	t_node	*tmp_node;
	t_node	*tmp_tree;
	t_node	*elem;

	elem = init_node(key);
	tmp_tree = (*tree);
	if (tmp_tree)
	{
		while (tmp_tree)
			place_node(key, &tmp_node, &tmp_tree, elem);
	}
	else
		(*tree) = elem;
}

void	clear_tree(t_node **tree)
{
	t_node	*tmp_tree;

	tmp_tree = (*tree);
	if (!tree)
		return ;
	if (tmp_tree->left)
		clear_tree(&tmp_tree->left);
	if (tmp_tree->right)
		clear_tree(&tmp_tree->right);
	free(tmp_tree);
	*tree = NULL;
}
