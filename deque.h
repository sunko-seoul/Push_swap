/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:07:59 by sunko             #+#    #+#             */
/*   Updated: 2023/06/22 14:55:41 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# define TRUE	1
# define FALSE	0

# include <stdlib.h>

typedef struct s_node
{
	int				data;
	unsigned int	idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque
{
	t_node			*head;
	t_node			*tail;
	unsigned int	num_of_data;
	unsigned int	total_size;
	unsigned int	sorting_num;
}	t_deque;

/* deque_util.c */
void	deque_init(t_deque *pdeque);
int		deque_is_empty(t_deque *pdeque);
int		deque_get_first(t_deque *pdeque);
int		deque_get_last(t_deque *pdeque);
void	delete_deque(t_deque *deq);

/* deque_operation.c */
t_node	*deque_add_first(t_deque *pdeque, int data);
t_node	*deque_add_last(t_deque *pdeque, int data);
int		deque_remove_first(t_deque *pdeque);
int		deque_remove_last(t_deque *pdeque);

#endif
