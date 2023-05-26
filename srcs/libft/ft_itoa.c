/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:06:15 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/07 09:53:33 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++size;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*p_str;

	if (n < 0)
		str = malloc(sizeof(char) * (ft_size(n) + 2));
	else
		str = malloc(sizeof(char) * (ft_size(n) + 1));
	if (!str)
		return (NULL);
	p_str = str;
	if (n < 0)
		*str++ = '-';
	str += ft_size(n);
	*str-- = '\0';
	if (n == 0)
		*str = '0';
	while (n != 0)
	{
		if (n < 0)
			*str-- = -(n % 10) + '0';
		else
			*str-- = n % 10 + '0';
		n /= 10;
	}
	return (p_str);
}
