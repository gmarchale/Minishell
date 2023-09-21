/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_key_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:59:35 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/21 13:16:42 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_value_to_new(char *str, char *new, int *j)
{
	t_env	*tmp;
	char	*key;
	char	*value;
	int		i;

	key = get_key(str);
	tmp = g_shell->env;
	if (!go_to_key(&tmp, key))
	{
		free(key);
		return ;
	}
	free(key);
	value = ft_strdup(tmp->value);
	if (!value)
		return ;
	i = 0;
	while (value[i])
	{
		new[*j] = value[i];
		i++;
		*j += 1;
	}
	free(value);
}

void	add_exit_value_to_new(char *new, int *j)
{
	int		i;
	char	*value;

	value = ft_itoa(g_shell->exit_value);
	if (!value)
		exit(g_shell->exit_value);
	i = 0;
	while (value[i])
	{
		new[*j] = value[i];
		i++;
		*j += 1;
	}
	free(value);
}

void	increment_both_int(int *i, int *j)
{
	if (!i || !j)
		return ;
	*i += 1;
	*j += 1;
}

void	copy_and_increment(t_lexlst *tmp, char *new, int *i, int *j)
{
	new[*j] = tmp->word[*i];
	increment_both_int(i, j);
}

void	copy_key_value(t_lexlst *tmp, char *new, int *i, int *j)
{
	if (tmp->word[*i + 1] == '?')
	{
		add_exit_value_to_new(new, j);
		*i += 2;
	}
	else if (ft_isalpha(tmp->word[*i + 1]))
	{
		add_value_to_new(&tmp->word[*i], new, j);
		*i += skip_key(&tmp->word[*i]);
	}
	else if (ft_isdigit(tmp->word[*i + 1]))
		*i += 2;
	else
		copy_and_increment(tmp, new, i, j);
}
