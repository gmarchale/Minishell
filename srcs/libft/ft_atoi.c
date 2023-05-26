/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:04:50 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/24 11:25:08 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_ctoi(long int nb, char c)
{
	nb = (nb * 10) + c - '0';
	return (nb);
}

int	ft_atoi(const char *str)
{
	long int	nb;
	long int	temp;
	int			neg;

	nb = 0;
	neg = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		temp = nb;
		nb = ft_ctoi(nb, *str);
		if (temp > nb && neg == 1)
			return (-1);
		else if (temp > nb && neg == -1)
			return (0);
		str++;
	}
	return (nb * neg);
}
