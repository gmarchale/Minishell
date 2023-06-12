/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:14:36 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/28 15:17:03 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(int fd, const char *str, ...);
int		ft_print_c(int fd, int c);
int		ft_print_s(int fd, char *str);
int		ft_print_p(int fd, void *ptr);
int		ft_print_d(int fd, int nb);
int		ft_print_i(int fd, int nb);
int		ft_print_u(int fd, unsigned int nb);
int		ft_print_x(int fd, int nb);
int		ft_print_caps_x(int fd, int nb);
int		ft_print_percent(int fd);
int		ft_print_error(void);
void	ft_putptr(int fd, unsigned long int nbr, char *base, int *count);
void	ft_putnbr_base(int fd, int nbr, char *base, int *count);
void	ft_putunbr_base(int fd, unsigned int nbr, char *base, int *count);

#endif
