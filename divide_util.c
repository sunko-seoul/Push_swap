/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:52:14 by sunko             #+#    #+#             */
/*   Updated: 2023/07/03 11:44:10 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_node_cnt(t_deque *b, long cnt)
{
	while (cnt)
	{
		reverse_rotate_b(b);
		cnt--;
	}
}

void	reverse_mid_small_cnt(t_deque *a, t_deque *b, t_info *info)
{
	int		mid_cnt;
	int		small_cnt;

	mid_cnt = info->mid_cnt;
	small_cnt = info->small_cnt;
	while (mid_cnt != 0 && small_cnt != 0)
	{
		reverse_rotate_rrr(a, b);
		mid_cnt--;
		small_cnt--;
	}
	while (mid_cnt == 0 && small_cnt != 0)
	{
		reverse_rotate_b(b);
		small_cnt--;
	}
	while (small_cnt == 0 && mid_cnt != 0)
	{
		reverse_rotate_a(a);
		mid_cnt--;
	}
}

void	not_under_hard_sort(t_deque *a, t_deque *b)
{
	if (check_ascending_util(a))
	{
		a->sorting_num += a->num_of_data;
		return ;
	}
	if (a->num_of_data == 2)
		sorting_two(a);
	else if (a->num_of_data == 3)
		sorting_three(a, a->total_size - 3);
	else if (a->num_of_data == 4)
		sorting_four(a, b, a->total_size - 4);
	else if (a->num_of_data == 5)
		sorting_five(a, b, a->total_size - 5);
	a->sorting_num += a->num_of_data;
}

void	push_a_cnt(t_deque *a, t_deque *b, long cnt)
{
	while (cnt)
	{
		push_a(a, b);
		cnt--;
	}
}
