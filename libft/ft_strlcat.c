/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:01:13 by sunko             #+#    #+#             */
/*   Updated: 2023/03/14 14:57:27 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		src_len;
	int			i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0 || dst_len >= dstsize)
		return (src_len + dstsize);
	else
	{
		dstsize -= dst_len;
		while ((dstsize - 1 > 0) && (src[i] != '\0'))
		{
			dst[dst_len + i] = src[i];
			i++;
			dstsize--;
		}
		dst[dst_len + i] = '\0';
		return (dst_len + src_len);
	}
}
