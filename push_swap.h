/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:49:11 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 11:49:35 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "deque.h"
# include "libft/libft.h"
# include "binary_tree.h"
# include "binary_search_tree.h"
# include "avl_rebalance.h"

typedef struct s_info
{
	long	pivot_s;
	long	pivot_l;
	long	cmd_cnt;
	long	small_cnt;
	long	mid_cnt;
	long	large_cnt;
}	t_info;

/* argv_check.c */
void	argv_check(int argc, char *arg[], t_tree **r, t_deque *d);
int		check_tmp_arr(t_tree **r, t_deque *d, char **arr, int idx);
char	**trim_split(char *str);
int		check_string(char *s);

/* err.c */
void	input_error(t_tree **root, t_deque *deq, char **arr, int idx);
void	malloc_error(void);
void	duplicate_error(t_tree **p_root, char **arr, int idx);

/* operation_push.c */
void	push_a(t_deque *deq_a, t_deque *deq_b);
void	push_b(t_deque *deq_a, t_deque *deq_b);

/* operation_reverse_rotate.c */
void	reverse_rotate_a(t_deque *deq_a);
void	reverse_rotate_b(t_deque *deq_b);
void	reverse_rotate_rrr(t_deque *deq_a, t_deque *deq_b);

/* operation_rotate.c */
void	rotate_a(t_deque *deq_a);
void	rotate_b(t_deque *deq_b);
void	rotate_duble(t_deque *deq_a, t_deque *deq_b);

/* operation_swap.c */
void	swap_a(t_deque *deq_a);
void	swap_b(t_deque *deq_b);
void	swap_ss(t_deque *deq_a, t_deque *deq_b);
void	swap_a_not_write(t_deque *deq_a);
void	swap_b_not_write(t_deque *deq_b);

/* index.c */
long	assing_index_inorder(t_tree *bt, long index);
void	init_info(t_info *info);

/* check.c */
int		check_ascending(t_deque *deq_a, t_deque *deq_b);
int		check_ascending_util(t_deque *deq_a);

/* sorting_hard_special.c */
void	sorting_two(t_deque *deq);
void	sorting_three(t_deque *deq_a, long i);
void	sorting_four(t_deque *deq_a, t_deque *deq_b, long i);
void	sorting_four_util(t_deque *deq_a, t_deque *deq_b, long i);
void	sorting_hard(t_deque *deq_a, t_deque *deq_b);

/* sorting_hard_five_special.c */
void	sorting_five(t_deque *deq_a, t_deque *deq_b, long i);
void	sorting_five_util(t_deque *deq_a, t_deque *deq_b, long i);
void	call_sorting_four(t_deque *deq_a, t_deque *deq_b, long i);

/* sorting_hard_general.c */
void	sorting_two_general(t_deque *deq);
void	sorting_three_general(t_deque *a, t_deque *b);
void	sorting_three_general_util(t_deque *a, t_deque *b);
void	sorting_four_general(t_deque *a, t_deque *b);
long	sorting_four_general_min(t_deque *a);

/* sorting_hard_five_general.c */
void	sorting_five_general(t_deque *a, t_deque *b);
int		sorting_five_general_core(t_deque *a, t_deque *b, long min, t_node *t);
long	sorting_five_general_min(t_deque *a);

/* sorting_hard_six_general.c */
void	sorting_six_general(t_deque *a, t_deque *b);
int		sorting_six_general_core(t_deque *a, t_deque *b, long min, t_node *t);
long	sorting_six_general_min(t_deque *a);

/* sorting_hard_seven_general.c */
void	sorting_seven_general(t_deque *a, t_deque *b);
int		sorting_seven_general_core(t_deque *a, t_deque *b, long min, t_node *t);
long	sorting_seven_general_min(t_deque *a);

/* sorting_hard_eight_general.c */
void	sorting_eight_general(t_deque *a, t_deque *b);
int		sorting_eight_general_core(t_deque *a, t_deque *b, long min, t_node *t);
long	sorting_eight_general_min(t_deque *a);

/* divide.c */
t_info	divide(t_deque *a, t_deque *b, long prev);
void	divide_m(t_deque *a, t_deque *b, t_info *info);
void	divide_s(t_deque *a, t_deque *b, t_info *info);
void	last_divide_s(t_deque *a, t_deque *b, t_info *prev_info);

/* divide_util.c */
void	reverse_node_cnt(t_deque *b, long cnt);
void	reverse_mid_small_cnt(t_deque *a, t_deque *b, t_info *info);
void	not_under_hard_sort(t_deque *a, t_deque *b);
void	push_a_cnt(t_deque *a, t_deque *b, long cnt);

/* divide_recursion.c */
t_info	merge_l_recur(t_deque *a, t_deque *b, t_info *prev_info, int flag);
t_info	merge_m_recur(t_deque *a, t_deque *b, t_info *prev_info, int flag);
t_info	merge_s_recur(t_deque *a, t_deque *b, t_info *prev_info, int flag);

/* divide_core.c */
void	divide_core(t_deque *a, t_deque *b, t_info *info);
void	merge_m_core(t_deque *a, t_deque *b, t_info *info, long c);
void	merge_s_core(t_deque *a, t_deque *b, t_info *info, long c);
void	last_merge_s_core(t_deque *a, t_deque *b, long cnt);

/* divide_recursion_util.c */
void	set_info_recur(t_info *info, long total_cnt, long max_idx);
void	merge_recur_core(t_deque *a, t_deque *b, t_info *info, long t_cnt);
void	rotate_large_mid_cnt(t_deque *a, t_deque *b, long l_cnt, long m_cnt);
void	goto_hard_sort(t_deque *a, t_deque *b, long cnt);

/* divide_recursion_hardsort.c */
void	goto_hard_sort(t_deque *a, t_deque *b, long cnt);
t_info	goto_hard_sort_l(t_deque *a, t_deque *b, t_info *prev_info, int flag);
t_info	goto_hard_sort_m(t_deque *a, t_deque *b, t_info *prev_info, int flag);
t_info	goto_hard_sort_s(t_deque *a, t_deque *b, t_info *prev_info, int flag);

/* divide_setting_info.c */
void	set_info(t_deque *a, t_info *info, long prev);
void	set_info_mid(t_info *info, t_info *prev_info);
void	set_info_small(t_info *info, t_info *prev_info);

#endif
