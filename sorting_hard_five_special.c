/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hard_five_special.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:51:09 by sunko             #+#    #+#             */
/*   Updated: 2023/07/03 12:10:52 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_five(t_deque *deq_a, t_deque *deq_b, long i)
{
	if (check_ascending_util(deq_a))
		return ;
	if (deq_a->head->idx == i)
	{
		call_sorting_four(deq_a, deq_b, i);
	}
	else if (deq_a->head->next->idx == i)
	{
		swap_a(deq_a);
		if (check_ascending_util(deq_a))
			return ;
		call_sorting_four(deq_a, deq_b, i);
	}
	else if (deq_a->head->next->next->idx == i)
	{
		rotate_a(deq_a);
		rotate_a(deq_a);
		if (check_ascending_util(deq_a))
			return ;
		call_sorting_four(deq_a, deq_b, i);
	}
	else
		sorting_five_util(deq_a, deq_b, i);
}

void	sorting_five_util(t_deque *deq_a, t_deque *deq_b, long i)
{
	if (deq_a->head->next->next->next->idx == i)
	{
		reverse_rotate_a(deq_a);
		reverse_rotate_a(deq_a);
		if (check_ascending_util(deq_a))
			return ;
		call_sorting_four(deq_a, deq_b, i);
	}
	else if (deq_a->tail->idx == i)
	{
		reverse_rotate_a(deq_a);
		if (check_ascending_util(deq_a))
			return ;
		call_sorting_four(deq_a, deq_b, i);
	}
}

void	call_sorting_four(t_deque *deq_a, t_deque *deq_b, long i)
{
	push_b(deq_a, deq_b);
	sorting_four(deq_a, deq_b, i + 1);
	push_a(deq_a, deq_b);
}
