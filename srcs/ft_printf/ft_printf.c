/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:36:17 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/27 15:23:33 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(int fd, const char c, va_list var)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_c(fd, va_arg(var, int));
	else if (c == 's')
		count = ft_print_s(fd, va_arg(var, char *));
	else if (c == 'p')
		count = ft_print_p(fd, va_arg(var, void *));
	else if (c == 'd')
		count = ft_print_d(fd, va_arg(var, int));
	else if (c == 'i')
		count = ft_print_i(fd, va_arg(var, int));
	else if (c == 'u')
		count = ft_print_u(fd, va_arg(var, unsigned int));
	else if (c == 'x')
		count = ft_print_x(fd, va_arg(var, int));
	else if (c == 'X')
		count = ft_print_caps_x(fd, va_arg(var, int));
	else if (c == '%')
		count = ft_print_percent(fd);
	else
		count = ft_print_error();
	return (count);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	var;
	int		count;

	va_start(var, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_conversion(fd, *str, var);
		}
		else
		{
			write(fd, str, 1);
			++count;
		}
		str++;
	}
	va_end(var);
	return (count);
}
