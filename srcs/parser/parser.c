/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:16:25 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/07 13:20:48 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	check_open_quote(char **split)
{
	int	i;
	int	j;
	int	d_count;
	int	s_count;

	if (!split)
		return (true);
	d_count = 0;
	s_count = 0;
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (split[i][j] == '\'' && d_count == 0 && s_count == 0)
				++s_count;
			else if (split[i][j] == '\'' && d_count == 0 && s_count == 1)
				--s_count;
			else if (split[i][j] == '"' && d_count == 0 && s_count == 0)
				++d_count;
			else if (split[i][j] == '"' && d_count == 1 && s_count == 0)
				--d_count;
			j++;
		}
		i++;
	}
	if (d_count || s_count)
		return (true);
	return (false);
}

bool syntax_error(char **split)
{
	if (check_open_quote(split))
		return (true);
	// else if (check_open_pipe(split))
	// 	return (true);
	// else if (check_open_redir(split))
	// 	return (true);
	return (false);
}

void lexer(char *line)
{
	char	**first_split;

	first_split = ft_split_set(line, " \t\r\v\f\n");
	if (!first_split)
		exit(1);
	if (syntax_error(first_split))
	{
		ft_printf(2, "Syntax error: do not leave open quotes/pipes/redirections\n");
	}
	//clear_quotes()
	// for (int i = 0; first_split[i]; ++i)
	// {
	// 	ft_printf(1, "[%s]\n", first_split[i]);
	// }
}