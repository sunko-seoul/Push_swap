/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:51:53 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 11:47:43 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_core(t_deque *a, t_deque *b, t_info *info)
{
	while (a->num_of_data > a->total_size - info->pivot_l)
	{
		if (a->head->idx < info->pivot_s)
		{
			push_b(a, b);
			rotate_b(b);
			info->small_cnt++;
		}
		else if (a->head->idx < info->pivot_l)
		{
			push_b(a, b);
			info->mid_cnt++;
		}
		else
		{
			rotate_a(a);
			info->large_cnt++;
		}
		info->cmd_cnt++;
	}
}

void	merge_m_core(t_deque *a, t_deque *b, t_info *info, long c)
{
	while (c)
	{
		if (b->head->idx < info->pivot_s)
		{
			rotate_b(b);
			info->small_cnt++;
		}
		else if (b->head->idx < info->pivot_l)
		{
			push_a(a, b);
			rotate_a(a);
			info->mid_cnt++;
		}
		else
		{
			push_a(a, b);
			info->large_cnt++;
		}
		c--;
	}
}

void	merge_s_core(t_deque *a, t_deque *b, t_info *info, long c)
{
	while (c)
	{
		if (b->head->idx < info->pivot_s)
		{
			rotate_b(b);
			info->small_cnt++;
		}
		else if (b->head->idx < info->pivot_l)
		{
			push_a(a, b);
			rotate_a(a);
			info->mid_cnt++;
		}
		else
		{
			push_a(a, b);
			info->large_cnt++;
		}
		c--;
	}
}

void	last_merge_s_core(t_deque *a, t_deque *b, long cnt)
{
	long	tmp;

	tmp = cnt;
	while (tmp--)
		push_a(a, b);
	goto_hard_sort(a, b, cnt);
}
