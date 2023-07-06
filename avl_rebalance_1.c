/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rebalance_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:57:05 by sunko             #+#    #+#             */
/*   Updated: 2023/05/29 18:11:19 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl_rebalance.h"

int	get_height(t_tree *bst)
{
	int		left_h;
	int		right_h;

	if (!bst)
		return (0);
	left_h = get_height(get_left_subtree(bst));
	right_h = get_height(get_right_subtree(bst));
	if (left_h > right_h)
		return (left_h + 1);
	else
		return (right_h + 1);
}

int	get_height_diff(t_tree *bst)
{
	int		lsh;
	int		rsh;

	if (!bst)
		return (0);
	lsh = get_height(get_left_subtree(bst));
	rsh = get_height(get_right_subtree(bst));
	return (lsh - rsh);
}

t_tree	*rebalance(t_tree	**p_root)
{
	int		diff;

	diff = get_height_diff(*p_root);
	if (diff > 1)
	{
		if (get_height_diff(get_left_subtree(*p_root)) > 0)
			*p_root = rotate_ll(*p_root);
		else
			*p_root = rotate_lr(*p_root);
	}
	else if (diff < -1)
	{
		if (get_height_diff(get_right_subtree(*p_root)) < 0)
			*p_root = rotate_rr(*p_root);
		else
			*p_root = rotate_rl(*p_root);
	}
	return (*p_root);
}
