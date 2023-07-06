/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:14:32 by sunko             #+#    #+#             */
/*   Updated: 2023/05/31 10:33:42 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_deque *deq_a, t_deque *deq_b)
{
	int				push_data;
	unsigned int	idx;

	if (deque_is_empty(deq_b))
		return ;
	idx = deq_b->head->idx;
	push_data = deque_remove_first(deq_b);
	if (!deque_add_first(deq_a, push_data))
		malloc_error();
	deq_a->head->idx = idx;
	write(1, "pa\n", 3);
}

void	push_b(t_deque *deq_a, t_deque *deq_b)
{
	int				push_data;
	unsigned int	idx;

	if (deque_is_empty(deq_a))
		return ;
	idx = deq_a->head->idx;
	push_data = deque_remove_first(deq_a);
	if (!deque_add_first(deq_b, push_data))
		malloc_error();
	deq_b->head->idx = idx;
	write(1, "pb\n", 3);
}
