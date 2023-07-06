/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_recursion_hardsort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:36:16 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 11:47:46 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	goto_hard_sort(t_deque *a, t_deque *b, long cnt)
{
	if (cnt == 1)
		;
	else if (cnt == 2)
		sorting_two_general(a);
	else if (cnt == 3)
		sorting_three_general(a, b);
	else if (cnt == 4)
		sorting_four_general(a, b);
	else if (cnt == 5)
		sorting_five_general(a, b);
	else if (cnt == 6)
		sorting_six_general(a, b);
	else if (cnt == 7)
		sorting_seven_general(a, b);
	a->sorting_num += cnt;
	return ;
}

t_info	goto_hard_sort_l(t_deque *a, t_deque *b, t_info *prev_info, int flag)
{
	goto_hard_sort(a, b, prev_info->large_cnt);
	if (flag == 1)
	{
		push_a_cnt(a, b, prev_info->mid_cnt);
		goto_hard_sort(a, b, prev_info->mid_cnt);
		push_a_cnt(a, b, prev_info->small_cnt);
		goto_hard_sort(a, b, prev_info->small_cnt);
	}
	return (*prev_info);
}

t_info	goto_hard_sort_m(t_deque *a, t_deque *b, t_info *prev_info, int flag)
{
	goto_hard_sort(a, b, prev_info->mid_cnt);
	if (flag == 1)
	{
		push_a_cnt(a, b, prev_info->mid_cnt);
		goto_hard_sort(a, b, prev_info->mid_cnt);
		push_a_cnt(a, b, prev_info->small_cnt);
		goto_hard_sort(a, b, prev_info->small_cnt);
	}
	return (*prev_info);
}

t_info	goto_hard_sort_s(t_deque *a, t_deque *b, t_info *prev_info, int flag)
{
	goto_hard_sort(a, b, prev_info->small_cnt);
	if (flag == 1)
	{
		push_a_cnt(a, b, prev_info->mid_cnt);
		goto_hard_sort(a, b, prev_info->mid_cnt);
		push_a_cnt(a, b, prev_info->small_cnt);
		goto_hard_sort(a, b, prev_info->small_cnt);
	}
	return (*prev_info);
}
