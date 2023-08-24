/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:31:06 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/21 18:28:59 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_token_error(t_lexlst *tmp)
{
	if (tmp->type == e_redir_in || tmp->type == e_redir_out || \
		tmp->type == e_heredoc || tmp->type == e_append)
	{
		if (!tmp->next || tmp->next->type == e_redir_in || \
			tmp->next->type == e_redir_out || tmp->next->type == e_heredoc || \
			tmp->next->type == e_append || tmp->next->type == e_pipe)
		{
			ft_printf(2, "minishell: syntax error\n");
			return (1);
		}
	}
	else if (tmp->type == e_pipe)
	{
		if (!tmp->next || tmp->next->type == e_pipe)
		{
			ft_printf(2, "minishell: syntax error\n");
			return (1);
		}
	}
	return (0);
}

void	parser(t_lexlst *lexlst)
{
	t_lexlst	*tmp;

	if (!lexlst)
		return ;
	tmp = lexlst;
	if (tmp->type == e_pipe)
	{
		ft_printf(2, "minishell: syntax error\n");
		return ;
	}
	while (tmp)
	{
		if (check_token_error(tmp))
			return ;
		tmp = tmp->next;
	}
}
