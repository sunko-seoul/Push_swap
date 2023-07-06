/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:53:17 by sunko             #+#    #+#             */
/*   Updated: 2023/03/14 20:53:37 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && !len)
		return (0);
	if (*needle == '\0')
		return ((char *)haystack);
	while (len > i && haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] && (i + j < len) && (haystack[i + j] == needle[j]))
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
