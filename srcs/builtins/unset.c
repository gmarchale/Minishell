/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:25 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 15:17:32 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	export_parsing(char *n_key)
{
	int	i;

	i = 0;
	if (!ft_isalpha(n_key[i]) && n_key[i] != '_')
		return (0);
	i++;
	while (n_key[i])
	{
		if (!ft_isalnum(n_key[i]) && n_key[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

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
	if (!export_parsing(str[i]))
	{
		ft_printf(2, \
		"minishell: unset: '%s': not a valid indentifier\n", \
		str[i]);
		shell->exit_value = 2;
		return ;
	}
	while (str[i])
	{
		key = str[i];
		unset_var(key);
		i++;
	}
}
