/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:59:23 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/16 13:45:22 by noloupe          ###   ########.fr       */
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
	i = 1;
	while (str[i] && check_option(str[i]))
	{
		new_line = 0;
		i++;
	}
	while (str[i])
	{
		ft_printf(1, "%s", str[i]);
		if (str[i + 1])
			ft_printf(1, " ");
		i++;
	}
	if (new_line == 1)
		ft_printf(1, "\n");
}
