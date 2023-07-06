/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:57:48 by sunko             #+#    #+#             */
/*   Updated: 2023/05/29 18:12:44 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

t_tree	*remove_left_subtree(t_tree *bt)
{
	t_tree	*del_node;

	if (!bt)
	{
		del_node = bt->left;
		bt->left = NULL;
	}
	else
		del_node = NULL;
	return (del_node);
}

t_tree	*remove_right_subtree(t_tree *bt)
{
	t_tree	*del_node;

	if (!bt)
	{
		del_node = bt->right;
		bt->right = NULL;
	}
	else
		del_node = NULL;
	return (del_node);
}

void	change_left_subtree(t_tree *main, t_tree *sub)
{
	main->left = sub;
}

void	change_right_subtree(t_tree *main, t_tree *sub)
{
	main->right = sub;
}

void	delete_tree(t_tree *bt)
{
	if (bt == NULL)
		return ;
	delete_tree(bt->left);
	delete_tree(bt->right);
	free(bt);
}
