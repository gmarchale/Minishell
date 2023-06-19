/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:24:43 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/19 14:24:03 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtin_env(char **str)
{
	t_env *tmp;

	if (str[1])
	{
		ft_printf(1, "env does not want any argument today \U0001f621\n");
		return ;
	}
	tmp = shell->env;
	while (tmp)
	{
		ft_printf(1, "%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
