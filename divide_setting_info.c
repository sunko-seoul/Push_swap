/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_setting_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:27:36 by sunko             #+#    #+#             */
/*   Updated: 2023/07/03 14:22:13 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_info(t_deque *a, t_info *info, long prev)
{
	info->cmd_cnt = 0;
	info->small_cnt = 0;
	info->mid_cnt = 0;
	info->large_cnt = 0;
	info->pivot_s = a->num_of_data / 3 + prev;
	info->pivot_l = a->num_of_data / 3 * 2 + prev;
}

void	set_info_mid(t_info *info, t_info *prev_info)
{
	info->large_cnt = 0;
	info->mid_cnt = 0;
	info->small_cnt = 0;
	info->pivot_l = prev_info->mid_cnt / 3 * 2 + prev_info->pivot_s;
	info->pivot_s = prev_info->mid_cnt / 3 + prev_info->pivot_s;
}

void	set_info_small(t_info *info, t_info *prev_info)
{
	long	cnt;

	cnt = prev_info->small_cnt;
	info->large_cnt = 0;
	info->mid_cnt = 0;
	info->small_cnt = 0;
	info->pivot_l = prev_info->pivot_s - cnt + (cnt / 3 * 2);
	info->pivot_s = prev_info->pivot_s - cnt + (cnt / 3);
}
