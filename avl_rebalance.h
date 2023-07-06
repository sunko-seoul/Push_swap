/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rebalance.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:21:57 by sunko             #+#    #+#             */
/*   Updated: 2023/05/29 18:11:08 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_REBALANCE_H
# define AVL_REBALANCE_H

# include "binary_tree.h"
# include "binary_search_tree.h"

/* avl_rebalance_1.c */
int		get_height(t_tree *bst);
int		get_height_diff(t_tree *bst);
t_tree	*rebalance(t_tree **p_root);

/* avl_rebalance_2.c */
t_tree	*rotate_ll(t_tree *bst);
t_tree	*rotate_rr(t_tree *bst);
t_tree	*rotate_lr(t_tree *bst);
t_tree	*rotate_rl(t_tree *bst);

#endif
