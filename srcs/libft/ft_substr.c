/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:06:53 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/24 14:24:42 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) >= len)
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		str[i] = s[start];
		++i;
		++start;
	}
	str[i] = '\0';
	return (str);
}
