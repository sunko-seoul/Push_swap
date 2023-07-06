/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:21:37 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 11:34:31 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	divide(t_deque *a, t_deque *b, long prev)
{
	t_info	info;
	t_info	return_info;

	if (a->num_of_data <= 5)
	{
		not_under_hard_sort(a, b);
		set_info(a, &info, prev);
		return (info);
	}
	set_info(a, &info, prev);
	divide_core(a, b, &info);
	return_info = divide(a, b, info.pivot_l);
	divide_m(a, b, &return_info);
	divide_s(a, b, &return_info);
	return (info);
}

void	divide_m(t_deque *a, t_deque *b, t_info *prev_info)
{
	t_info	info;
	int		i;
	long	cnt;

	set_info_mid(&info, prev_info);
	cnt = prev_info->mid_cnt;
	i = -1;
	if (cnt == 0)
		return ;
	merge_m_core(a, b, &info, cnt);
	merge_l_recur(a, b, &info, 0);
	reverse_mid_small_cnt(a, b, &info);
	merge_m_recur(a, b, &info, 0);
	push_a_cnt(a, b, info.small_cnt);
	merge_s_recur(a, b, &info, 0);
}

void	divide_s(t_deque *a, t_deque *b, t_info *prev_info)
{
	t_info	info;
	long	cnt;

	set_info_small(&info, prev_info);
	cnt = prev_info->small_cnt;
	if (cnt == 0)
		return ;
	reverse_node_cnt(b, cnt);
	merge_s_core(a, b, &info, cnt);
	merge_l_recur(a, b, &info, 0);
	reverse_mid_small_cnt(a, b, &info);
	merge_m_recur(a, b, &info, 0);
	push_a_cnt(a, b, info.small_cnt);
	merge_s_recur(a, b, &info, 0);
}

void	last_divide_s(t_deque *a, t_deque *b, t_info *prev_info)
{
	t_info	info;
	long	cnt;

	set_info_small(&info, prev_info);
	cnt = prev_info->small_cnt;
	if (cnt == 0)
		return ;
	if (cnt <= 5 && a->total_size <= 17)
		return (last_merge_s_core(a, b, cnt));
	merge_s_core(a, b, &info, cnt);
	merge_l_recur(a, b, &info, 0);
	reverse_mid_small_cnt(a, b, &info);
	merge_m_recur(a, b, &info, 0);
	push_a_cnt(a, b, info.small_cnt);
	merge_s_recur(a, b, &info, 0);
}
