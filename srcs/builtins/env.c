/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:24:43 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/21 13:12:39 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sort_env(t_env **cpy)
{
	t_env	*tmp;
	char	*tmp_key;
	char	*tmp_value;

	tmp = *cpy;
	while (tmp->next)
	{
		if (ft_strncmp(tmp->key, tmp->next->key, \
		(ft_strlen(tmp->next->key) + 1)) > 0)
		{
			tmp_key = tmp->key;
			tmp_value = tmp->value;
			tmp->key = tmp->next->key;
			tmp->value = tmp->next->value;
			tmp->next->key = tmp_key;
			tmp->next->value = tmp_value;
			tmp = *cpy;
		}
		else
			tmp = tmp->next;
	}
}

t_env	*create_sorted_env_cpy(void)
{
	t_env	*tmp;
	t_env	*cpy;

	cpy = NULL;
	tmp = g_shell->env;
	while (tmp)
	{
		add_node(&cpy, tmp->key, tmp->value);
		tmp = tmp->next;
	}
	if (cpy)
		sort_env(&cpy);
	return (cpy);
}

void	export_print(void)
{
	t_env	*tmp;

	tmp = create_sorted_env_cpy();
	while (tmp)
	{
		if (tmp->value)
			ft_printf(1, "declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		else
			ft_printf(1, "declare -x %s\n", tmp->key);
		tmp = tmp->next;
	}
	if (tmp)
		free_env_list(tmp);
}

void	env_print(char **str)
{
	t_env	*tmp;

	if (str[1])
	{
		ft_printf(1, "env does not want any argument today \U0001f621\n");
		g_shell->exit_value = 127;
		return ;
	}
	tmp = g_shell->env;
	while (tmp)
	{
		if (tmp->value)
			ft_printf(1, "%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

void	builtin_env(char **str, int mode)
{
	if (mode == e_env)
		env_print(str);
	else if (mode == e_export)
		export_print();
}
