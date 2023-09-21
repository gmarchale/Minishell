/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:43:02 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/18 17:47:25 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	type_word(t_cmd **cmd, t_lexlst **lexlst, int *i)
{
	(*cmd)->cmd[*i] = ft_strdup((*lexlst)->word);
	*i += 1;
}

int	type_pipe(t_cmd **cmd, int *i, int *stop)
{
	(*cmd)->cmd[*i] = NULL;
	*stop = 0;
	(*cmd)->next = cmd_new_node();
	*cmd = (*cmd)->next;
	return (1);
}

void	type_redir_in(t_cmd **cmd, t_lexlst **lexlst)
{
	if ((*cmd)->fd_in != 0)
		close((*cmd)->fd_in);
	(*cmd)->fd_in = get_fd((*lexlst)->next->word, (*lexlst)->type);
	*lexlst = (*lexlst)->next;
}

void	type_redir_out(t_cmd **cmd, t_lexlst **lexlst)
{
	if ((*cmd)->fd_out != 1)
		close((*cmd)->fd_out);
	(*cmd)->fd_out = get_fd((*lexlst)->next->word, (*lexlst)->type);
	*lexlst = (*lexlst)->next;
}
