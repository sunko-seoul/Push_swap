/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:29:46 by sunko             #+#    #+#             */
/*   Updated: 2023/05/29 17:12:59 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_search_tree.h"

void	bst_make_init(t_tree **p_root)
{
	*p_root = NULL;
}

int	bst_get_node_data(t_tree *bst)
{
	return (get_data(bst));
}

t_tree	*bst_insert(t_tree **p_root, int data)
{
	t_tree	*node;

	if (*p_root == NULL)
	{
		*p_root = make_btree_node();
		if (*p_root == NULL)
			return (NULL);
		set_data(*p_root, data);
		return (*p_root);
	}
	if (data == get_data(*p_root))
		return (NULL);
	else if (data < get_data(*p_root))
	{
		node = bst_insert(&((*p_root)->left), data);
		if (!node)
			return (NULL);
	}
	else
	{
		node = bst_insert(&((*p_root)->right), data);
		if (!node)
			return (NULL);
	}
	return (node);
}
