/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:03:00 by sunko             #+#    #+#             */
/*   Updated: 2023/03/14 20:37:27 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;

	i = -1;
	if (!dst && !src)
		return (NULL);
	dst_tmp = (unsigned char *)dst;
	src_tmp = (const unsigned char *)src;
	if (dst >= src)
	{
		while (++i < len)
			dst_tmp[len - i - 1] = src_tmp[len - i - 1];
	}
	else
	{
		while (++i < len)
			dst_tmp[i] = src_tmp[i];
	}
	return (dst);
}
