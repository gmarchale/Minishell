/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:55:03 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/07 14:05:50 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool is_set(char c, char *set)
{
	int	i;

	if (!set)
		return (false);
	i = -1;
	while (set[++i])
	{
		if (c == set[i])
			return (true);
	}
	return (false);
}

int	count_words(char *str, char *set)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if ((!is_set(str[i], set) && is_set(str[i + 1], set)) || \
			(!is_set(str[i], set) && str[i + 1] == '\0'))
			++count;
	}
	return (count);
}
char	*word_to_tab(char *str, char *set)
{
	char	*word;
	int	i;
	int	j;

	i = 0;
	while (str[i] && !is_set(str[i], set))
		++i;
	word = ft_calloc(i + 1, sizeof(char));
	if (!word)
		return (NULL);
	j = -1;
	while (++j < i)
		word[j] = str[j];
	word[j] = '\0';
	return (word);
}

char	**ft_split_set(char *str, char *set)
{
	char	**split;
	char	**p_split;
	
	split = ft_calloc(count_words(str, set) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	p_split = split;
	while (*str)
	{
		while (is_set(*str, set))
			str++;
		if (!*str)
			break ;
		*split = word_to_tab(str, set);
		if (!*split)
		{
			ft_free_split(p_split);
			return (NULL);
		}
		str +=ft_strlen(*split++);
	}
	*split = NULL;

	for (int i = 0; p_split[i]; ++i)
		ft_printf(1, "[%s]\n", p_split[i]);
	return (p_split);
}
