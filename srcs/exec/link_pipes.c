/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:40:02 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 14:40:29 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	link_ins(t_cmd *cmdlst, int pipes[2][2])
{
	if (pipes[0][0] != -1)
	{
		if (dup2(pipes[0][0], STDIN_FILENO) == -1)
			perror_exit("dup2", EXIT_FAILURE);
	}
	else if (cmdlst->fd_in != STDIN_FILENO)
	{
		if (dup2(cmdlst->fd_in, STDIN_FILENO) == -1)
			perror_exit("dup2", EXIT_FAILURE);
		close(cmdlst->fd_in);
	}
	close(pipes[0][0]);
	close(pipes[0][1]);
}

void	link_outs(t_cmd *cmdlst, int pipes[2][2])
{
	if (cmdlst->fd_out == STDOUT_FILENO)
	{
		if (dup2(pipes[1][1], STDOUT_FILENO) == -1)
			perror_exit("dup2", EXIT_FAILURE);
	}
	else if (cmdlst->fd_out != STDOUT_FILENO)
	{
		if (dup2(cmdlst->fd_out, STDOUT_FILENO) == -1)
			perror_exit("dup2", EXIT_FAILURE);
		close(cmdlst->fd_out);
	}
	close(pipes[1][0]);
	close(pipes[1][1]);
}

void	link_pipe(t_cmd *cmdlst, int pipes[2][2])
{
	link_ins(cmdlst, pipes);
	link_outs(cmdlst, pipes);
}

void	last_link(t_cmd *cmdlst, int pipes[2])
{
	if (cmdlst->fd_in != STDIN_FILENO)
	{
		if (pipes[0] != -1)
			close(pipes[0]);
		dup2(cmdlst->fd_in, STDIN_FILENO);
	}
	else if (pipes[0] != -1)
	{
		dup2(pipes[0], STDIN_FILENO);
		close(pipes[0]);
	}
	if (cmdlst->fd_out != STDOUT_FILENO)
	{
		dup2(cmdlst->fd_out, STDOUT_FILENO);
		close(cmdlst->fd_out);
	}
}
