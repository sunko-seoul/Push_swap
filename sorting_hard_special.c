/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hard_special.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:10:51 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 11:46:06 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_hard(t_deque *deq_a, t_deque *deq_b)
{
	if (deq_a->num_of_data == 2 && deq_b->num_of_data == 0)
	{
		sorting_two(deq_a);
		deq_a->sorting_num += 2;
	}
	else if (deq_a->num_of_data == 3 && deq_b->num_of_data == 0)
	{
		sorting_three(deq_a, 0);
		deq_a->sorting_num += 3;
	}
	else if (deq_a->num_of_data == 4 && deq_b->num_of_data == 0)
	{
		sorting_four(deq_a, deq_b, 0);
		deq_a->sorting_num += 4;
	}
	else if (deq_a->num_of_data == 5 && deq_b->num_of_data == 0)
	{
		sorting_five(deq_a, deq_b, 0);
		deq_a->sorting_num += 5;
	}
	if (check_ascending(deq_a, deq_b))
		delete_deque(deq_a);
}

void	sorting_two(t_deque *deq)
{
	swap_a(deq);
}

void	sorting_three(t_deque *deq_a, long i)
{
	if (check_ascending_util(deq_a))
		return ;
	if (deq_a->head->idx == i)
	{
		swap_a(deq_a);
		rotate_a(deq_a);
	}
	else if (deq_a->head->idx == i + 1 && deq_a->head->next->idx == i)
		swap_a(deq_a);
	else if (deq_a->head->idx == i + 1 && deq_a->head->next->idx == i + 2)
	{
		reverse_rotate_a(deq_a);
	}
	else if (deq_a->head->idx == i + 2 && deq_a->head->next->idx == i)
		rotate_a(deq_a);
	else if (deq_a->head->idx == i + 2 && deq_a->head->next->idx == i + 1)
	{
		swap_a(deq_a);
		reverse_rotate_a(deq_a);
	}
}

void	sorting_four(t_deque *deq_a, t_deque *deq_b, long i)
{
	if (check_ascending_util(deq_a))
		return ;
	if (deq_a->head->idx == i)
	{
		push_b(deq_a, deq_b);
		sorting_three(deq_a, i + 1);
		push_a(deq_a, deq_b);
	}
	else if (deq_a->tail->idx == i)
	{
		reverse_rotate_a(deq_a);
		if (check_ascending_util(deq_a))
			return ;
		push_b(deq_a, deq_b);
		sorting_three(deq_a, i + 1);
		push_a(deq_a, deq_b);
	}
	else
		sorting_four_util(deq_a, deq_b, i);
}

void	sorting_four_util(t_deque *deq_a, t_deque *deq_b, long i)
{
	if (deq_a->head->next->idx == i)
	{
		swap_a(deq_a);
		if (check_ascending_util(deq_a))
			return ;
		push_b(deq_a, deq_b);
		sorting_three(deq_a, i + 1);
		push_a(deq_a, deq_b);
	}
	else
	{
		reverse_rotate_a(deq_a);
		reverse_rotate_a(deq_a);
		if (check_ascending_util(deq_a))
			return ;
		push_b(deq_a, deq_b);
		sorting_three(deq_a, i + 1);
		push_a(deq_a, deq_b);
	}
}
