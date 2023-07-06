/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:00:41 by sunko             #+#    #+#             */
/*   Updated: 2023/05/30 22:07:30 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_error(t_tree **p_root, t_deque *deque, char **arr, int idx)
{
	while (arr[idx] != NULL)
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
	while (deque->head != NULL)
		deque_remove_first(deque);
	delete_tree(*p_root);
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	malloc_error(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	duplicate_error(t_tree **p_root, char **arr, int idx)
{
	while (arr[idx] != NULL)
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
	delete_tree(*p_root);
}
