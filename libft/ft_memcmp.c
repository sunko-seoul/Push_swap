/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:14:23 by sunko             #+#    #+#             */
/*   Updated: 2023/03/14 21:12:26 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	i = 0;
	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_temp[i] == s2_temp[i])
			i++;
		else
			return (s1_temp[i] - s2_temp[i]);
	}
	return (0);
}
