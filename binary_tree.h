/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:04:44 by sunko             #+#    #+#             */
/*   Updated: 2023/05/29 18:12:21 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include <stdlib.h>
# include "deque.h"

typedef struct s_tree_node
{
	int					data;
	struct s_node		*n_ptr;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree;

/* binary_tree_1.c */
t_tree			*make_btree_node(void);
t_tree			*get_left_subtree(t_tree *bt);
t_tree			*get_right_subtree(t_tree *bt);
void			make_left_subtree(t_tree *main, t_tree *sub);
void			make_right_subtree(t_tree *main, t_tree *sub);

/* binary_tree_2.c */
typedef void	t_visit_func_ptr(int data);
void			preorder_traverse(t_tree *bt, t_visit_func_ptr action);
void			inorder_traverse(t_tree *bt, t_visit_func_ptr action);
void			postorder_traverse(t_tree *bt, t_visit_func_ptr action);
int				get_data(t_tree *bt);
void			set_data(t_tree *bt, int data);

/* binary_tree_3.c */
t_tree			*remove_left_subtree(t_tree *bt);
t_tree			*remove_right_subtree(t_tree *bt);
void			change_left_subtree(t_tree *main, t_tree *sub);
void			change_right_subtree(t_tree *main, t_tree *sub);
void			delete_tree(t_tree *bt);

#endif
