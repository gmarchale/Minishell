/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:23:43 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/27 15:28:47 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int fd, int c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_print_s(int fd, char *str)
{
	int	count;

	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	count = ft_strlen(str);
	write(fd, str, count);
	return (count);
}

int	ft_print_p(int fd, void *ptr)
{
	unsigned long int	ad;
	int					count;

	if (!ptr)
	{
		write(fd, "0x0", 3);
		return (3);
	}
	count = 0;
	ad = (unsigned long int)ptr;
	write(fd, "0x", 2);
	ft_putptr(fd, ad, "0123456789abcdef", &count);
	return (count + 2);
}

int	ft_print_d(int fd, int nb)
{
	int	count;

	count = 0;
	ft_putnbr_base(fd, nb, "0123456789", &count);
	return (count);
}

int	ft_print_i(int fd, int nb)
{
	int	count;

	count = 0;
	ft_putnbr_base(fd, nb, "0123456789", &count);
	return (count);
}
