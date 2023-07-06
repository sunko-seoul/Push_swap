/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:35:37 by sunko             #+#    #+#             */
/*   Updated: 2023/07/06 11:38:42 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_check(int argc, char *argv[], t_tree **p_root, t_deque *deq)
{
	int				i;
	int				j;
	char			**arr;
	t_tree			*tnode;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		arr = trim_split(argv[i]);
		if (!arr)
			malloc_error();
		while (arr[++j] != NULL)
		{
			tnode = bst_insert(p_root, check_tmp_arr(p_root, deq, arr, j));
			if (!tnode)
				input_error(p_root, deq, arr, j);
			rebalance(p_root);
			tnode->n_ptr = deque_add_last(deq, tnode->data);
			if (!tnode)
				input_error(p_root, deq, arr, j);
			free(arr[j]);
		}
		free(arr);
	}
}

int	check_tmp_arr(t_tree **p_root, t_deque *deq, char **arr, int idx)
{
	long long	input;

	if (!check_string(arr[idx]))
		input_error(p_root, deq, arr, idx);
	input = ft_atoi(arr[idx]);
	if (input > 2147483647 || input < -2147483648)
		input_error(p_root, deq, arr, idx);
	return (input);
}

char	**trim_split(char *str)
{
	char	*tmp;
	char	**tmp_arr;
	int		i;

	i = -1;
	tmp = ft_strtrim(str, " ");
	if (!tmp)
		return (NULL);
	if (tmp[0] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	tmp_arr = ft_split(tmp, ' ');
	free(tmp);
	if (!tmp_arr)
		return (NULL);
	return (tmp_arr);
}

int	check_string(char *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-'\
			|| s[i] == ' '))
			return (0);
		if (s[i] == '+' || s[i] == '-')
		{
			if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
				return (0);
		}
		i++;
	}
	return (1);
}
