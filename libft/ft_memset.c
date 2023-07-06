/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:38:46 by sunko             #+#    #+#             */
/*   Updated: 2023/03/14 21:21:15 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_tmp;

	b_tmp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_tmp[i] = (unsigned char)c;
		i++;
	}
	return (b_tmp);
}
