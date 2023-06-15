/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:59:23 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/15 10:35:08 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_option(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		while (str[i] == 'n')
			i++;
	}
	if (str[i])
		return (0);
	return (1);
}

void builtin_echo(char **str)
{
	int	i;
	int new_line;
	
	new_line = 1;
	i = 0;
	while (str[i])
	{
		if (check_option(str[i]))
		{
			new_line = 0;
			i++;
		}
		else
			break ;
	}
	while (str[i + 1])
	{
		ft_printf(1, "%s ", str[i]);
		i++;
	}
	ft_printf(1, "%s", str[i]);
	if (new_line == 1)
		ft_printf(1, "\n");
}
