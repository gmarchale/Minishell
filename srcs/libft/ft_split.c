/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:29:07 by noloupe           #+#    #+#             */
/*   Updated: 2023/03/24 16:13:59 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_words(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			++count;
		s++;
	}
	return (count);
}

static char	*ft_word_to_array(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			*word;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < i)
	{
		word[j] = s[j];
		++j;
	}
	word[j] = '\0';
	return (word);
}

static void	ft_free_all(char **p_split)
{
	while (*p_split)
		free(*p_split++);
	free(p_split);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	char			**p_split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	p_split = split;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		*split = ft_word_to_array(s, c);
		if (!*split)
		{
			ft_free_all(p_split);
			return (NULL);
		}
		s += ft_strlen(*split++);
	}
	*split = NULL;
	return (p_split);
}
