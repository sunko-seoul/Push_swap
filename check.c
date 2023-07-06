/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:25:56 by sunko             #+#    #+#             */
/*   Updated: 2023/07/03 14:21:19 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ascending(t_deque *deq_a, t_deque *deq_b)
{
	t_node	*head;

	head = deq_b->head;
	if (!deque_is_empty(deq_b))
		return (FALSE);
	head = deq_a->head;
	while (head->next != NULL)
	{
		if (head->idx > head->next->idx)
			return (FALSE);
		head = head->next;
	}
	return (TRUE);
}

int	check_ascending_util(t_deque *deq_a)
{
	t_node	*head;

	head = deq_a->head;
	while (head->next != NULL)
	{
		if (head->idx > head->next->idx)
			return (FALSE);
		head = head->next;
	}
	return (TRUE);
}
