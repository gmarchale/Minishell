/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:09:24 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/18 17:52:36 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_new_i(int i, char *cmd_line)
{
	while (cmd_line[i] && !is_set(cmd_line[i], "\011\012\013\014\015\040"))
	{
		if (is_token(&cmd_line[i]))
		{
			i += is_token(&cmd_line[i]);
			break ;
		}
		else
		{
			while (cmd_line[i] && !is_set(cmd_line[i], "\011\012\013\014\015\040") 
				&& !is_token(&cmd_line[i]))
			{
				if (cmd_line[i] == '\'' || cmd_line[i] == '"')
					i += size_quotes(&cmd_line[i]);
				else
					i++;
			}
			break ;
		}
	}
	return (i);
}

void	ft_split_lexer(char *cmd_line, t_lexlst **lexer_lst)
{
	int		i;
	int		old_i;
	char	*buffer;

	i = 0;
	while (cmd_line[i])
	{
		while (is_set(cmd_line[i], "\011\012\013\014\015\040"))
			i++;
		if (cmd_line[i])
		{
			old_i = i;
			i = get_new_i(i, cmd_line);
			buffer = ft_substr(cmd_line, old_i, i - old_i);
			lex_lstadd_back(lexer_lst, lexlst_new(buffer));
		}
	}
}

int	get_type(char *line)
{
	if (!ft_strncmp(line, "|", 2))
		return (e_pipe);
	else if (!ft_strncmp(line, "<", 2))
		return (e_redir_in);
	else if (!ft_strncmp(line, ">", 2))
		return (e_redir_out);
	else if (!ft_strncmp(line, "<<", 3))
		return (e_heredoc);
	else if (!ft_strncmp(line, ">>", 3))
		return (e_append);
	else
		return (e_word);
}

void	get_token_types(t_lexlst **lexlst)
{
	t_lexlst	*tmp;

	tmp = *lexlst;
	while (tmp && tmp->word)
	{
		tmp->type = get_type(tmp->word);
		tmp = tmp->next;
	}
	tmp = *lexlst;
	while (tmp)
	{
		if (tmp->next && tmp->type == e_heredoc && tmp->next->type == e_word)
			tmp->next->type = e_limiter;
		tmp = tmp->next;
	}
}

t_lexlst	*lexer(char *cmd_line)
{
	t_lexlst	*lexer_lst;

	if (checker_quotes(cmd_line))
	{
		ft_printf(1, "Do not leave open quotes\n");
		return (NULL);
	}
	lexer_lst = NULL;
	ft_split_lexer(cmd_line, &lexer_lst);
	get_token_types(&lexer_lst);
	return (lexer_lst);
}
