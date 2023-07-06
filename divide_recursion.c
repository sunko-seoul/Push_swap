/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_recursion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:50:05 by sunko             #+#    #+#             */
/*   Updated: 2023/07/03 11:55:03 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	merge_l_recur(t_deque *a, t_deque *b, t_info *prev_info, int flag)
{
	t_info	info;
	long	total_cnt;
	long	max_idx;

	total_cnt = prev_info->large_cnt;
	if (total_cnt <= 5)
		return (goto_hard_sort_l(a, b, prev_info, flag));
	max_idx = a->total_size - a->sorting_num;
	set_info_recur(&info, total_cnt, max_idx);
	merge_recur_core(a, b, &info, total_cnt);
	rotate_large_mid_cnt(a, b, info.large_cnt, info.mid_cnt);
	merge_l_recur(a, b, &info, 1);
	if (info.mid_cnt > 5 && info.small_cnt > 5)
	{
		push_a_cnt(a, b, info.mid_cnt);
		merge_m_recur(a, b, &info, 1);
		push_a_cnt(a, b, info.small_cnt);
		merge_s_recur(a, b, &info, 1);
	}
	return (info);
}

t_info	merge_m_recur(t_deque *a, t_deque *b, t_info *prev_info, int flag)
{
	t_info	info;
	int		total_cnt;
	int		max_idx;

	total_cnt = (int)prev_info->mid_cnt;
	if (total_cnt <= 5)
		return (goto_hard_sort_m(a, b, prev_info, flag));
	max_idx = (int)(a->total_size - a->sorting_num);
	set_info_recur(&info, total_cnt, max_idx);
	merge_recur_core(a, b, &info, total_cnt);
	rotate_large_mid_cnt(a, b, (int)info.large_cnt, (int)info.mid_cnt);
	merge_l_recur(a, b, &info, 1);
	if (info.mid_cnt > 5 && info.small_cnt > 5)
	{
		push_a_cnt(a, b, info.mid_cnt);
		merge_m_recur(a, b, &info, 1);
		push_a_cnt(a, b, info.small_cnt);
		merge_s_recur(a, b, &info, 1);
	}
	return (info);
}

t_info	merge_s_recur(t_deque *a, t_deque *b, t_info *prev_info, int flag)
{
	t_info	info;
	int		total_cnt;
	int		max_idx;

	total_cnt = (int)prev_info->small_cnt;
	if (total_cnt <= 5)
		return (goto_hard_sort_s(a, b, prev_info, flag));
	max_idx = (int)(a->total_size - a->sorting_num);
	set_info_recur(&info, total_cnt, max_idx);
	merge_recur_core(a, b, &info, total_cnt);
	rotate_large_mid_cnt(a, b, (int)info.large_cnt, (int)info.mid_cnt);
	merge_l_recur(a, b, &info, 1);
	if (info.mid_cnt > 5 && info.small_cnt > 5)
	{
		push_a_cnt(a, b, info.mid_cnt);
		merge_m_recur(a, b, &info, 1);
		push_a_cnt(a, b, info.small_cnt);
		merge_s_recur(a, b, &info, 1);
	}
	return (info);
}
