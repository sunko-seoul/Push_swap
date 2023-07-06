/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:19:52 by sunko             #+#    #+#             */
/*   Updated: 2023/05/26 22:49:40 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

int	get_data(t_tree *bt)
{
	return (bt->data);
}

void	set_data(t_tree *bt, int data)
{
	bt->data = data;
}

void	preorder_traverse(t_tree *bt, t_visit_func_ptr action)
{
	if (!bt)
		return ;
	action(bt->data);
	preorder_traverse(bt->left, action);
	preorder_traverse(bt->right, action);
}

void	inorder_traverse(t_tree *bt, t_visit_func_ptr action)
{
	if (!bt)
		return ;
	inorder_traverse(bt->left, action);
	action(bt->data);
	inorder_traverse(bt->right, action);
}

void	postorder_traverse(t_tree *bt, t_visit_func_ptr action)
{
	if (!bt)
		return ;
	postorder_traverse(bt->left, action);
	postorder_traverse(bt->right, action);
	action(bt->data);
}
