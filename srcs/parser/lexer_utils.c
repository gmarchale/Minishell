/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:10:44 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/18 17:52:27 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	checker_quotes(char *line)
{
	int	s;
	int	d;

	s = 0;
	d = 0;
	while (*line)
	{
		if (*line == '\'' && s == 0 && d == 0)
			s++;
		else if (*line == '\'' && s == 1 && d == 0)
			s--;
		else if (*line == '\"' && d == 0 && s == 0)
			d++;
		else if (*line == '\"' && d == 1 && s == 0)
			d--;
		line++;
	}
	if (s != 0 || d != 0)
		return (1);
	return (0);
}

int	size_quotes(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\'')
			i++;
	}
	else if (str[i] == '\"')
	{
		i++;
		while (str[i] != '\"')
			i++;
	}
	return (i + 1);
}

int	is_token(char *str)
{
	if (*str == '|')
		return (1);
	else if (*str == '<' || *str == '>')
	{
		if (*str == '<' && *(str + 1) == '<')
			return (2);
		if (*str == '>' && *(str + 1) == '>')
			return (2);
		else
			return (1);
	}
	return (0);
}

int	skip_quotes(char *line, int *dq)
{
	int	i;

	i = 0;
	if (line[i] == '\"')
		*dq = -*dq;
	if (*dq == -1)
	{
		if (line[i] == '\'')
		{
			i++;
			while (line[i] != '\'')
				i++;
		}
	}
	return (i);
}

bool	is_set(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (true);
		i++;
	}
	return (false);
}
