/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:07:34 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 11:46:48 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_tree		*root;
	t_deque		deq_a;
	t_deque		deq_b;
	t_info		info;

	if (argc == 1)
		return (0);
	bst_make_init(&root);
	deque_init(&deq_a);
	deque_init(&deq_b);
	argv_check(argc, argv, &root, &deq_a);
	assing_index_inorder(root, 0);
	delete_tree(root);
	if (check_ascending(&deq_a, &deq_b))
		delete_deque(&deq_a);
	deq_a.total_size = deq_a.num_of_data;
	deq_b.total_size = deq_a.total_size;
	deq_a.sorting_num = 0;
	deq_b.sorting_num = 0;
	sorting_hard(&deq_a, &deq_b);
	info = divide(&deq_a, &deq_b, 0);
	divide_m(&deq_a, &deq_b, &info);
	last_divide_s(&deq_a, &deq_b, &info);
	delete_deque(&deq_a);
	delete_deque(&deq_b);
}
