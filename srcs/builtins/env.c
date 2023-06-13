/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:24:43 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/13 16:27:18 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtin_env(t_env **env)
{
	t_env *tmp;

	tmp = *env;
	while (tmp)
	{
		ft_printf(1, "%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
