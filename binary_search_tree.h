/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:20:47 by sunko             #+#    #+#             */
/*   Updated: 2023/05/29 17:12:11 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_H
# define BINARY_SEARCH_TREE_H

# include "binary_tree.h"

/* binary_search_tree_1.c */
t_tree		*bst_insert(t_tree **p_root, int data);
void		bst_make_init(t_tree **p_root);
int			bst_get_node_data(t_tree *bst);

#endif
