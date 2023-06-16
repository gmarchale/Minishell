/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:50:02 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/16 10:54:35 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int key_check(char *key, char *word)
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