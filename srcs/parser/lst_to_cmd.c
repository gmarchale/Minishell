/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:55:22 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/21 13:16:08 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*cmd_new_node(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		exit(g_shell->exit_value);
	new->cmd = NULL;
	new->fd_in = 0;
	new->fd_out = 1;
	new->next = NULL;
	return (new);
}

int	get_arr_size(t_lexlst *lexlst)
{
	int	count;

	count = 0;
	while (lexlst)
	{
		if (lexlst->type == e_word)
			count++;
		else if (lexlst->type == e_pipe)
			return (count);
		lexlst = lexlst->next;
	}
	return (count);
}

int	get_fd(char *str, int type)
{
	int	fd;

	fd = 0;
	if (type == e_redir_in)
		fd = open(str, O_RDONLY);
	else if (type == e_redir_out)
		fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == e_append)
		fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

int	make_arr_and_get_fds(t_cmd **cmd, t_lexlst **lexlst, int *i, int *stop)
{
	if ((*lexlst)->type == e_word)
		type_word(cmd, lexlst, i);
	else if ((*lexlst)->type == e_pipe)
		return (type_pipe(cmd, i, stop));
	else if ((*lexlst)->type == e_redir_in && *stop == 0)
		type_redir_in(cmd, lexlst);
	else if ((*lexlst)->type == e_redir_out && *stop == 0)
		type_redir_out(cmd, lexlst);
	else if ((*lexlst)->type == e_heredoc)
		(*cmd)->fd_in = create_heredoc((*lexlst)->next->word);
	else if ((*lexlst)->type == e_append && *stop == 0)
		type_redir_out(cmd, lexlst);
	if ((*cmd)->fd_in == -1 || (*cmd)->fd_out == -1)
	{
		(*cmd)->fd_in = -2;
		(*cmd)->fd_out = -2;
		*stop = 1;
		perror("fd");
	}
	*lexlst = (*lexlst)->next;
	return (0);
}

t_cmd	*lst_to_cmd(t_lexlst *lexlst)
{
	t_cmd		*cmd;
	t_cmd		*save;
	int			stop;
	int			i;

	cmd = cmd_new_node();
	save = cmd;
	stop = 0;
	while (lexlst)
	{
		cmd->cmd = malloc(sizeof(char *) * (get_arr_size(lexlst) + 1));
		if (cmd->cmd == NULL)
			exit(g_shell->exit_value);
		i = 0;
		while (lexlst)
		{
			if (make_arr_and_get_fds(&cmd, &lexlst, &i, &stop))
				break ;
		}
		if (lexlst)
			lexlst = lexlst->next;
	}
	cmd->cmd[i] = NULL;
	return (save);
}
