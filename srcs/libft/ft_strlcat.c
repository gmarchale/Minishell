/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:28:01 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/07 13:38:17 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	slen = 0;
	while (src[slen])
		++slen;
	if (!dst && dstsize == 0)
		return (slen);
	i = 0;
	while (dst[i] && i < dstsize)
		++i;
	dlen = i;
	j = 0;
	if (dstsize != 0)
	{
		while (src[j] && i < dstsize - 1)
			dst[i++] = src[j++];
	}
	if (i > dlen)
		dst[i] = '\0';
	return (dlen + slen);
}
