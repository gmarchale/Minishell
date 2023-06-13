/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:25 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/13 16:48:12 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtin_unset(t_env **env, char *key)
{
	t_env *tmp;
	t_env *prev;

	tmp = *env;
	prev = NULL;
	while (tmp)
	{
		if (!ft_memcmp(tmp->key, key, ft_strlen(key)))
		{
			if (prev == NULL)
				*env = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
