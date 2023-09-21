/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:53:35 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/21 13:17:16 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_size(char *key)
{
	t_env	*tmp;

	tmp = g_shell->env;
	if (!go_to_key(&tmp, key))
	{
		free(key);
		return (0);
	}
	free(key);
	return ((int)ft_strlen(tmp->value));
}

char	*get_key(char *str)
{
	char	*key;
	int		i;

	i = 1;
	while (ft_isalnum(str[i]))
		i++;
	key = malloc(sizeof(char) * i);
	if (!key)
		exit(g_shell->exit_value);
	i = 1;
	while (ft_isalnum(str[i]))
	{
		key[i - 1] = str[i];
		i++;
	}
	key[i - 1] = '\0';
	return (key);
}

int	get_env_value_size(char	*str)
{
	char	*buffer;

	buffer = get_key(str);
	return (get_size(buffer));
}
