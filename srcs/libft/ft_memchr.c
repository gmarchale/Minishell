/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:45:26 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/07 15:16:02 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		++i;
		str++;
	}
	return (NULL);
}
