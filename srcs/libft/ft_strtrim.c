/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:49:01 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/07 09:57:23 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

static char const	*ft_begin(char const *s1, char const *set)
{
	while (*s1 && ft_is_set(*s1, set))
		s1++;
	return (s1);
}

static size_t	ft_check_len(char const *s1, char const *set)
{
	size_t	strlen;

	strlen = ft_strlen(s1);
	if (strlen == 0)
		return (0);
	while (ft_is_set(s1[strlen - 1], set))
		--strlen;
	return (strlen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	s1 = ft_begin(s1, set);
	str = malloc(sizeof(char) * (ft_check_len(s1, set) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (ft_is_set(s1[i], set))
		++i;
	j = 0;
	while (i < ft_check_len(s1, set))
	{
		str[j] = s1[i];
		++i;
		++j;
	}
	str[j] = '\0';
	return (str);
}
