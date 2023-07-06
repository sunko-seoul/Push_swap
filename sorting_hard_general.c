/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hard_general.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:54:45 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 11:30:24 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_two_general(t_deque *deq)
{
	if (deq->head->idx > deq->head->next->idx)
		swap_a(deq);
	return ;
}

void	sorting_three_general(t_deque *a, t_deque *b)
{
	if (check_ascending_util(a))
		return ;
	if (a->head->idx == a->head->next->idx - 2 && \
	a->head->idx == a->head->next->next->idx - 1)
	{
		rotate_a(a);
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (a->head->idx == a->head->next->idx + 1 && \
	a->head->idx == a->head->next->next->idx - 1)
		swap_a(a);
	else if (a->head->idx == a->head->next->idx - 1 && \
	a->head->idx == a->head->next->next->idx + 1)
	{
		rotate_a(a);
		push_b(a, b);
		rotate_a(a);
		push_a(a, b);
		reverse_rotate_a(a);
		reverse_rotate_a(a);
		swap_a(a);
	}
	else
		sorting_three_general_util(a, b);
}

void	sorting_three_general_util(t_deque *a, t_deque *b)
{
	if (a->head->idx == a->head->next->idx + 2 && \
	a->head->idx == a->head->next->next->idx + 1)
	{
		push_b(a, b);
		rotate_a(a);
		rotate_a(a);
		push_a(a, b);
		reverse_rotate_a(a);
		reverse_rotate_a(a);
	}
	else if (a->head->idx == a->head->next->idx + 1 && \
	a->head->idx == a->head->next->next->idx + 2)
	{
		push_b(a, b);
		swap_a(a);
		rotate_a(a);
		rotate_a(a);
		push_a(a, b);
		reverse_rotate_a(a);
		reverse_rotate_a(a);
	}
}

void	sorting_four_general(t_deque *a, t_deque *b)
{
	int		cnt;
	long	min;
	t_node	*tmp;

	cnt = 0;
	min = sorting_four_general_min(a);
	if (min == -1)
		return ;
	tmp = a->head;
	while (tmp->idx != min)
	{
		tmp = tmp->next;
		rotate_a(a);
		cnt++;
	}
	push_b(a, b);
	while (cnt--)
		reverse_rotate_a(a);
	sorting_three_general(a, b);
	push_a(a, b);
}

long	sorting_four_general_min(t_deque *a)
{
	t_node		*tmp;
	long		min;
	long		cnt;
	int			i;

	tmp = a->head;
	min = a->head->idx;
	i = 0;
	cnt = 0;
	while (++i < 4)
	{
		if (tmp->idx + 1 == tmp->next->idx)
			cnt++;
		tmp = tmp->next;
		if (min > tmp->idx)
			min = tmp->idx;
	}
	if (cnt == 3)
		min = -1;
	return (min);
}
