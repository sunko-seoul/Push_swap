/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:57:28 by sunko             #+#    #+#             */
/*   Updated: 2023/03/16 15:06:13 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len] != '\0')
		len++;
	while (i < len)
	{
		f((unsigned char)i, s);
		i++;
		s++;
	}
}
