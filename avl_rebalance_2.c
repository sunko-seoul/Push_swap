/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rebalance_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:57:12 by sunko             #+#    #+#             */
/*   Updated: 2023/05/26 22:46:49 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"
#include "binary_search_tree.h"

t_tree	*rotate_ll(t_tree *bst)
{
	t_tree	*p_node;
	t_tree	*c_node;

	p_node = bst;
	c_node = get_left_subtree(p_node);
	change_left_subtree(p_node, get_right_subtree(c_node));
	change_right_subtree(c_node, p_node);
	return (c_node);
}

t_tree	*rotate_rr(t_tree *bst)
{
	t_tree	*p_node;
	t_tree	*c_node;

	p_node = bst;
	c_node = get_right_subtree(p_node);
	change_right_subtree(p_node, get_left_subtree(c_node));
	change_left_subtree(c_node, p_node);
	return (c_node);
}

t_tree	*rotate_lr(t_tree *bst)
{
	t_tree	*p_node;
	t_tree	*c_node;

	p_node = bst;
	c_node = get_left_subtree(p_node);
	change_left_subtree(p_node, rotate_rr(c_node));
	return (rotate_ll(p_node));
}

t_tree	*rotate_rl(t_tree *bst)
{
	t_tree	*p_node;
	t_tree	*c_node;

	p_node = bst;
	c_node = get_right_subtree(p_node);
	change_right_subtree(p_node, rotate_ll(c_node));
	return (rotate_rr(p_node));
}
