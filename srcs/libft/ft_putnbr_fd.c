/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:24:58 by noloupe           #+#    #+#             */
/*   Updated: 2022/10/07 17:03:58 by noloupe          ###   ########.fr       */
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

static long int	ft_ln_to_char(long int ln)
{
	if (ln < 0)
		ln = -ln % 10 + '0';
	else
		ln = ln % 10 + '0';
	return (ln);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	long int		ln;
	char			s[11];

	if (fd < 0)
		return ;
	i = ft_size(n);
	if (n == 0)
	{
		s[0] = '0';
		s[1] = 0;
	}
	else
		s[i--] = 0;
	ln = (long int)n;
	if (ln < 0)
		write(fd, "-", 1);
	while (ln != 0)
	{
		s[i--] = ft_ln_to_char(ln);
		ln /= 10;
	}
	ft_putstr_fd(s, fd);
}
