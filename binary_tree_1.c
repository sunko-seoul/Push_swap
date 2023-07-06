/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:12:41 by sunko             #+#    #+#             */
/*   Updated: 2023/05/29 11:53:27 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

t_tree	*make_btree_node(void)
{
	t_tree	*new_node;

	new_node = (t_tree *)malloc(sizeof(t_tree));
	if (!new_node)
		return (NULL);
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

t_tree	*get_left_subtree(t_tree *bt)
{
	return (bt->left);
}

t_tree	*get_right_subtree(t_tree *bt)
{
	return (bt->right);
}

void	make_left_subtree(t_tree *main, t_tree *sub)
{
	if (main->left != NULL)
		free(main->left);
	main->left = sub;
}

void	make_right_subtree(t_tree *main, t_tree *sub)
{
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}
