/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:51:11 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/19 14:55:45 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int check_doubles(t_env **env, char *n_key)
{
	t_env *tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_memcmp(tmp->key, n_key, ft_strlen(n_key)))
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int export_parsing(char *n_key)
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

static int parse_var(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

static void export_var(char **n_key, char **n_value)
{
	t_env *tmp;

	tmp = shell->env;
	if (!export_parsing(*n_key))
	{
		ft_printf(2, "minishell: export: `%s': not a valid indentifier\n", *n_key);
		return ;
	}
	if (!check_doubles(&shell->env, *n_key)) 
	{
		add_node(&shell->env, *n_key, *n_value);
		return ;
	}
	while (ft_memcmp(tmp->key, *n_key, ft_strlen(*n_key)))
		tmp = tmp->next;
	free(tmp->value);
	tmp->value = ft_strdup(*n_value);
}

void builtin_export(char **str)
{
	char	*n_key;
	char	*n_value;
	int		i;
	
	i = 1;
	if (!str[i])
		return ; // print list w/ "declare -x"
	while (str[i])
	{
		if (!parse_var(str[i]))
			ft_printf(1, "need to add %s for export\n", str[i]); // to add for export
		else
		{
			n_key = ft_strdup(str[i]);
			n_value = n_key;
			while (*n_value != '=')
				n_value++;
			*n_value = '\0';
			n_value++;
			export_var(&n_key, &n_value);
			free(n_key);
		}
		i++;
	}
}
