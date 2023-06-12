/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:46:38 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/27 15:31:10 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_base(int fd, unsigned int nbr, char *base, int *count)
{
	long int	nb;
	int			baselen;

	if (!base)
		return ;
	nb = nbr;
	baselen = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		++(*count);
		nb *= -1;
	}
	while (base[baselen])
		++baselen;
	if (nb >= baselen)
	{
		ft_putunbr_base(fd, nb / baselen, base, count);
		nb %= baselen;
	}
	if (nb < baselen)
	{
		write(fd, &base[nb], 1);
		++(*count);
	}
}
