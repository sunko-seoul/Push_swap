/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:24:09 by sunko             #+#    #+#             */
/*   Updated: 2023/05/31 10:31:09 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_deque *deq_a)
{
	int				rotate_data;
	unsigned int	idx;

	if (deq_a->num_of_data <= 1)
		return ;
	idx = deq_a->tail->idx;
	rotate_data = deque_remove_last(deq_a);
	if (!deque_add_first(deq_a, rotate_data))
		malloc_error();
	deq_a->head->idx = idx;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_deque *deq_b)
{
	int				rotate_data;
	unsigned int	idx;

	if (deq_b->num_of_data <= 1)
		return ;
	idx = deq_b->tail->idx;
	rotate_data = deque_remove_last(deq_b);
	if (!deque_add_first(deq_b, rotate_data))
		malloc_error();
	deq_b->head->idx = idx;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_rrr(t_deque *deq_a, t_deque *deq_b)
{
	int				rotate_data;
	unsigned int	a_idx;
	unsigned int	b_idx;

	if (deq_a->num_of_data <= 1)
		return ;
	a_idx = deq_a->tail->idx;
	rotate_data = deque_remove_last(deq_a);
	if (!deque_add_first(deq_a, rotate_data))
		malloc_error();
	deq_a->head->idx = a_idx;
	if (deq_b->num_of_data <= 1)
		return ;
	b_idx = deq_b->tail->idx;
	rotate_data = deque_remove_last(deq_b);
	if (!deque_add_first(deq_b, rotate_data))
		malloc_error();
	deq_b->head->idx = b_idx;
	write(1, "rrr\n", 4);
}
