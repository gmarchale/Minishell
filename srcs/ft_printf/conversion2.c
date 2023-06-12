/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:10:33 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/28 15:17:53 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(int fd, unsigned int nb)
{
	int	count;

	count = 0;
	ft_putunbr_base(fd, (int)nb, "0123456789", &count);
	return (count);
}

int	ft_print_x(int fd, int nb)
{
	int	count;

	count = 0;
	ft_putunbr_base(fd, nb, "0123456789abcdef", &count);
	return (count);
}

int	ft_print_caps_x(int fd, int nb)
{
	int	count;

	count = 0;
	ft_putunbr_base(fd, nb, "0123456789ABCDEF", &count);
	return (count);
}

int	ft_print_percent(int fd)
{
	write(fd, "%", 1);
	return (1);
}

int	ft_print_error(void)
{
	write(2, "[error: unknown conversion type character]", 42);
	return (42);
}
