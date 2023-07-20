/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:25 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/26 11:29:18 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset_var(char *key)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = shell->env;
	prev = NULL;
	while (tmp)
	{
		if (key_check(tmp->key, key))
		{
			if (prev == NULL)
				shell->env = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp->key);
			if (tmp->value)
				free(tmp->value);
			free(tmp);
			break ;
		}
		prev = tmp;
		tmp = prev->next;
	}
}

void	builtin_unset(char **str)
{
	char	*key;
	int		i;

	i = 1;
	if (!str[i])
		return ;
	while (str[i])
	{
		key = str[i];
		unset_var(key);
		i++;
	}
}
