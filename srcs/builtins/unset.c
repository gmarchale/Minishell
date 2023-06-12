/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:25 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/12 14:59:23 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtin_unset(t_env **env, char *key)
{
	t_env *env_cpy;
	t_env *tmp;

	tmp = NULL;
	env_cpy = *env;
	ft_printf(1, "env_key:	%s\nsrch_key:	%s\n", (*env)->key, key);
	if (!memcmp((*env)->key, key, strlen(key)))
	{
		ft_printf(1, "same\n");
		*env = (*env)->next;
		free(env_cpy->key);
		free(env_cpy->value);
		free(env_cpy);
		return ;
	}
	ft_printf(1, "not same\n");
	// while (env_cpy->next && env_cpy->next->key != key)
	// {
	// 	env_cpy = env_cpy->next;
	// }
	// if (env_cpy->next->key == key)
	// {
	// 	tmp = env_cpy;
	// 	env_cpy = env_cpy->next;
	// 	tmp->next = env_cpy->next;
	// 	free(env_cpy->key);
	// 	free(env_cpy->value);
	// 	free(env_cpy);
	// }
}
