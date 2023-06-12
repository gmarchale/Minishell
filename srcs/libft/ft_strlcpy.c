/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:28:56 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/07 14:16:28 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		++len;
	if (dstsize == 0)
		return (len);
	i = -1;
	while (src[++i] && i < dstsize)
		dst[i] = src[i];
	if (len >= dstsize)
		dst[i - 1] = '\0';
	else
		dst[i] = '\0';
	return (len);
}
