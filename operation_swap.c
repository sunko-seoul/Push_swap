/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:14:24 by sunko             #+#    #+#             */
/*   Updated: 2023/07/03 11:56:35 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_deque *deq_a)
{
	int				tmp_first;
	int				tmp_second;
	unsigned int	tmp_first_idx;
	unsigned int	tmp_second_idx;

	if (deq_a->num_of_data < 2)
		return ;
	tmp_first_idx = deq_a->head->idx;
	tmp_second_idx = deq_a->head->next->idx;
	tmp_first = deque_remove_first(deq_a);
	tmp_second = deque_remove_first(deq_a);
	if (!deque_add_first(deq_a, tmp_first))
		malloc_error();
	if (!deque_add_first(deq_a, tmp_second))
		malloc_error();
	deq_a->head->idx = tmp_second_idx;
	deq_a->head->next->idx = tmp_first_idx;
	write(1, "sa\n", 3);
}

void	swap_b(t_deque *deq_b)
{
	int				tmp_first;
	int				tmp_second;
	unsigned int	tmp_first_idx;
	unsigned int	tmp_second_idx;

	if (deq_b->num_of_data < 2)
		return ;
	tmp_first_idx = deq_b->head->idx;
	tmp_second_idx = deq_b->head->next->idx;
	tmp_first = deque_remove_first(deq_b);
	tmp_second = deque_remove_first(deq_b);
	if (!deque_add_first(deq_b, tmp_first))
		malloc_error();
	if (!deque_add_first(deq_b, tmp_second))
		malloc_error();
	deq_b->head->idx = tmp_second_idx;
	deq_b->head->next->idx = tmp_first_idx;
	write(1, "sb\n", 3);
}

void	swap_ss(t_deque *deq_a, t_deque *deq_b)
{
	swap_a_not_write(deq_a);
	swap_b_not_write(deq_b);
	write(1, "ss\n", 3);
}

void	swap_a_not_write(t_deque *deq_a)
{
	int				tmp_first;
	int				tmp_second;
	unsigned int	tmp_first_idx;
	unsigned int	tmp_second_idx;

	if (deq_a->num_of_data < 2)
		return ;
	tmp_first_idx = deq_a->head->idx;
	tmp_second_idx = deq_a->head->next->idx;
	tmp_first = deque_remove_first(deq_a);
	tmp_second = deque_remove_first(deq_a);
	if (!deque_add_first(deq_a, tmp_first))
		malloc_error();
	if (!deque_add_first(deq_a, tmp_second))
		malloc_error();
	deq_a->head->idx = tmp_second_idx;
	deq_a->head->next->idx = tmp_first_idx;
}

void	swap_b_not_write(t_deque *deq_b)
{
	int				tmp_first;
	int				tmp_second;
	unsigned int	tmp_first_idx;
	unsigned int	tmp_second_idx;

	if (deq_b->num_of_data < 2)
		return ;
	tmp_first_idx = deq_b->head->idx;
	tmp_second_idx = deq_b->head->next->idx;
	tmp_first = deque_remove_first(deq_b);
	tmp_second = deque_remove_first(deq_b);
	if (!deque_add_first(deq_b, tmp_first))
		malloc_error();
	if (!deque_add_first(deq_b, tmp_second))
		malloc_error();
	deq_b->head->idx = tmp_second_idx;
	deq_b->head->next->idx = tmp_first_idx;
}
