/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:50:02 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/26 11:28:59 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	go_to_key(t_env **tmp, char *key)
{
	while (*tmp)
	{
		if (key_check((*tmp)->key, key))
			return (1);
		*tmp = (*tmp)->next;
	}
	return (0);
}

char	*dup_env_value(char *key)
{
	t_env	*tmp;
	char	*value;

	value = NULL;
	tmp = shell->env;
	if (go_to_key(&tmp, key))
		value = tmp->value;
	return (value);
}

int	key_check(char *key, char *word)
{
	size_t	key_len;
	size_t	word_len;

	if (!key || !word)
		return (0);
	key_len = ft_strlen(key);
	word_len = ft_strlen(word);
	if (word_len == key_len && !ft_strncmp(key, word, key_len))
		return (1);
	return (0);
}
