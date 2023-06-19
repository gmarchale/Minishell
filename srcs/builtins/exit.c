/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:52:48 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/19 09:39:09 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int is_overflow(long int arg, int neg)
{
	if ((arg > INT_MAX && neg > 0) || (arg > (unsigned int)INT_MIN && neg < 0))
		return (1);
	return (0);
}

long int check_arg(char *str, int *overflow)
{
	int			i;
	int			neg;
	long int	arg;

	i = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	arg = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || is_overflow(arg, neg))
		{
			if (!ft_isdigit(str[i]))
				*overflow = 1;
			return (arg * neg);
		}
		arg = arg * 10 + str[i] - 48;
		i++;
	}
	return (arg * neg);
}

void builtin_exit(char **str)
{
	long	arg;
	int		overflow;
	
	ft_printf(1, "exit\n");
	if (!str[1])
		exit(shell->exit_value);
	overflow = 0;
	arg = check_arg(str[1], &overflow);
	if (overflow)
	{
		ft_printf(1, "minishell: exit: numeric argument required\n");
		exit(2);
	}
	if (!str[2])
		exit(arg);
	else
		ft_printf(1, "minishell: exit: too many arguments\n");
}
