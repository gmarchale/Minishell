/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:46:13 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 14:46:34 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_env_size(void)
{
	t_env	*save;
	int		i;

	save = shell->env;
	i = 0;
	while (save)
	{
		i++;
		save = save->next;
	}
	return (i);
}

char	**env_to_list(void)
{
	t_env	*save;
	char	**env;
	int		i;

	env = malloc(sizeof(char *) * (get_env_size() + 1));
	if (!env)
		exit(shell->exit_value);
	save = shell->env;
	i = 0;
	while (save)
	{
		env[i] = ft_strdup(save->key);
		env[i] = strjoin_free_first(env[i], "=");
		env[i] = strjoin_free_first(env[i], save->value);
		i++;
		save = save->next;
	}
	env[i] = NULL;
	return (env);
}
