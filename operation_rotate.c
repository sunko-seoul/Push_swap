/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:18:53 by sunko             #+#    #+#             */
/*   Updated: 2023/05/31 10:37:02 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_deque *deq_a)
{
	int				rotate_data;
	unsigned int	idx;

	if (deq_a->num_of_data <= 1)
		return ;
	idx = deq_a->head->idx;
	rotate_data = deque_remove_first(deq_a);
	if (!deque_add_last(deq_a, rotate_data))
		malloc_error();
	deq_a->tail->idx = idx;
	write(1, "ra\n", 3);
}

void	rotate_b(t_deque *deq_b)
{
	int				rotate_data;
	unsigned int	idx;

	if (deq_b->num_of_data <= 1)
		return ;
	idx = deq_b->head->idx;
	rotate_data = deque_remove_first(deq_b);
	if (!deque_add_last(deq_b, rotate_data))
		malloc_error();
	deq_b->tail->idx = idx;
	write(1, "rb\n", 3);
}

void	rotate_duble(t_deque *deq_a, t_deque *deq_b)
{
	int				rotate_data;
	unsigned int	a_idx;
	unsigned int	b_idx;

	if (deq_a->num_of_data <= 1)
		return ;
	a_idx = deq_a->head->idx;
	rotate_data = deque_remove_first(deq_a);
	if (!deque_add_last(deq_a, rotate_data))
		malloc_error();
	deq_a->tail->idx = a_idx;
	if (deq_b->num_of_data <= 1)
		return ;
	b_idx = deq_b->head->idx;
	rotate_data = deque_remove_first(deq_b);
	if (!deque_add_last(deq_b, rotate_data))
		malloc_error();
	deq_b->tail->idx = b_idx;
	write(1, "rr\n", 3);
}
