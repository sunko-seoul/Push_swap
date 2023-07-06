/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:00:36 by sunko             #+#    #+#             */
/*   Updated: 2023/07/05 22:47:39 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "libft/libft.h"

void	deque_init(t_deque *pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
	pdeq->num_of_data = 0;
	pdeq->total_size = 0;
	pdeq->sorting_num = 0;
}

int	deque_is_empty(t_deque *pdeq)
{
	if (pdeq->head == NULL)
		return (TRUE);
	else
		return (FALSE);
}

int	deque_get_first(t_deque *pdeq)
{
	if (deque_is_empty(pdeq))
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	return (pdeq->head->data);
}

int	deque_get_last(t_deque *pdeq)
{
	if (deque_is_empty(pdeq))
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	return (pdeq->tail->data);
}

void	delete_deque(t_deque *deq)
{
	t_deque	*pdeq;
	t_node	*head;
	long	cnt;
	long	i;

	pdeq = deq;
	cnt = deq->num_of_data;
	i = 0;
	head = pdeq->head;
	while (i < cnt)
	{
		deque_remove_first(pdeq);
		i++;
	}
	exit(EXIT_SUCCESS);
}
