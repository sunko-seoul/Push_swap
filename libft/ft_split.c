/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:03:30 by sunko             #+#    #+#             */
/*   Updated: 2023/03/16 21:02:20 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cnt_str_case(char const *s, char c)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			cnt++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (cnt);
}

static char	*ft_input_str(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

void	*free_str_case(char **str_case, int idx)
{
	int		i;

	i = 0;
	while (i < idx)
	{
		free(str_case[i]);
		i++;
	}
	free(str_case);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str_case;

	i = 0;
	str_case = (char **)malloc(sizeof(char *) * (ft_cnt_str_case(s, c) + 1));
	if (!str_case)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s == '\0')
			break ;
		str_case[i] = ft_input_str(s, c);
		if (!str_case[i])
			return (free_str_case(str_case, i));
		i++;
		while (*s != '\0' && *s != c)
			s++;
	}
	str_case[i] = 0;
	return (str_case);
}
