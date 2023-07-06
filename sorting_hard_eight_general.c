/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hard_eight_general.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:55:07 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 10:30:32 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_eight_general(t_deque *a, t_deque *b)
{
	long	min;
	int		rotate_cnt;
	t_node	*tmp;

	min = sorting_seven_general_min(a);
	if (min == -1)
		return ;
	tmp = a->head;
	rotate_cnt = sorting_seven_general_core(a, b, min, tmp);
	while (rotate_cnt--)
		reverse_rotate_a(a);
	sorting_four_general(a, b);
	push_a(a, b);
	push_a(a, b);
	push_a(a, b);
	push_a(a, b);
	sorting_four_general(a, b);
}

int	sorting_eight_general_core(t_deque *a, t_deque *b, long min, t_node *tmp)
{
	int		cnt;
	int		rotate_cnt;
	int		i;

	cnt = 0;
	rotate_cnt = 0;
	i = -1;
	while (++i < 8)
	{
		if (tmp->idx >= min && tmp->idx <= min + 3)
		{
			tmp = tmp->next;
			push_b(a, b);
			cnt++;
			if (cnt == 4)
				break ;
		}
		else
		{
			rotate_cnt++;
			tmp = tmp->next;
			rotate_a(a);
		}
	}
	return (rotate_cnt);
}

long	sorting_eight_general_min(t_deque *a)
{
	t_node	*tmp;
	long	min;
	long	cnt;
	int		i;

	tmp = a->head;
	min = a->head->idx;
	i = 0;
	cnt = 0;
	while (++i < 8)
	{
		if (tmp->idx + 1 == tmp->next->idx)
			cnt++;
		tmp = tmp->next;
		if (min > tmp->idx)
			min = tmp->idx;
	}
	if (cnt == 7)
		min = -1;
	return (min);
}
