/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:30:53 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 11:46:46 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	assing_index_inorder(t_tree *bt, long index)
{
	if (bt)
	{
		index = assing_index_inorder(bt->left, index);
		bt->n_ptr->idx = index;
		index++;
		index = assing_index_inorder(bt->right, index);
	}
	return (index);
}

void	init_info(t_info *info)
{
	info->cmd_cnt = 0;
	info->large_cnt = 0;
	info->mid_cnt = 0;
	info->small_cnt = 0;
	info->pivot_l = 0;
	info->pivot_s = 0;
}
