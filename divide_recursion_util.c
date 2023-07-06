/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_recursion_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:44:59 by sunko             #+#    #+#             */
/*   Updated: 2023/07/03 12:03:28 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_recur_core(t_deque *a, t_deque *b, t_info *info, long t_cnt)
{
	while (t_cnt)
	{
		if (a->head->idx < info->pivot_s)
		{
			push_b(a, b);
			info->small_cnt++;
		}
		else if (a->head->idx < info->pivot_l)
		{
			push_b(a, b);
			rotate_b(b);
			info->mid_cnt++;
		}
		else
		{
			rotate_a(a);
			info->large_cnt++;
		}
		t_cnt--;
	}
}

void	set_info_recur(t_info *info, long total_cnt, long max_idx)
{
	info->pivot_l = max_idx - (total_cnt / 3);
	info->pivot_s = max_idx - (total_cnt / 3) * 2;
	info->cmd_cnt = 0;
	info->large_cnt = 0;
	info->mid_cnt = 0;
	info->small_cnt = 0;
}

void	rotate_large_mid_cnt(t_deque *a, t_deque *b, long l_cnt, long m_cnt)
{
	while (m_cnt != 0 && l_cnt != 0)
	{
		reverse_rotate_rrr(a, b);
		l_cnt--;
		m_cnt--;
	}
	if (l_cnt == 0 && m_cnt != 0)
	{
		while (m_cnt)
		{
			reverse_rotate_b(b);
			m_cnt--;
		}
	}
	else if (l_cnt != 0 && m_cnt == 0)
	{
		while (l_cnt)
		{
			reverse_rotate_a(a);
			l_cnt--;
		}
	}
}
