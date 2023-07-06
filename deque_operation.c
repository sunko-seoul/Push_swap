/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:28:51 by sunko             #+#    #+#             */
/*   Updated: 2023/07/03 17:27:41 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include "libft/libft.h"

t_node	*deque_add_first(t_deque *pdeq, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = pdeq->head;
	if (pdeq->head == NULL)
		pdeq->tail = new_node;
	else
		pdeq->head->prev = new_node;
	pdeq->head = new_node;
	(pdeq->num_of_data)++;
	return (new_node);
}

t_node	*deque_add_last(t_deque *pdeq, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = pdeq->tail;
	if (pdeq->tail == NULL)
		pdeq->head = new_node;
	else
		pdeq->tail->next = new_node;
	pdeq->tail = new_node;
	(pdeq->num_of_data)++;
	return (new_node);
}

int	deque_remove_first(t_deque *pdeq)
{
	t_node	*rnode;
	int		rdata;

	if (deque_is_empty(pdeq))
		return (0);
	rnode = pdeq->head;
	rdata = pdeq->head->data;
	pdeq->head = pdeq->head->next;
	if (rnode != NULL)
		free(rnode);
	if (!pdeq->head)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;
	(pdeq->num_of_data)--;
	return (rdata);
}

int	deque_remove_last(t_deque *pdeq)
{
	t_node	*rnode;
	int		rdata;

	if (deque_is_empty(pdeq))
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	rnode = pdeq->tail;
	rdata = pdeq->tail->data;
	pdeq->tail = pdeq->tail->prev;
	free(rnode);
	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;
	(pdeq->num_of_data)--;
	return (rdata);
}
