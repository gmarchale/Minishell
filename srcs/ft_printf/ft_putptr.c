/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:12:46 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/27 15:30:57 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(int fd, unsigned long int nbr, char *base, int *count)
{
	unsigned long int	baselen;

	baselen = ft_strlen(base);
	if (nbr >= baselen)
	{
		ft_putptr(fd, nbr / baselen, base, count);
		nbr %= baselen;
	}
	if (nbr < baselen)
	{
		write(fd, &base[nbr], 1);
		++(*count);
	}
}
