/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:18:36 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/07 14:27:46 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p_s;

	p_s = s;
	while (*s)
	{
		if (*s == (char)c)
			p_s = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if (*p_s == (char)c)
		return ((char *)p_s);
	return (NULL);
}
