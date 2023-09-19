/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:44:44 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 14:45:26 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_pipes(int pipes[2][2])
{
	pipes[0][0] = -1;
	pipes[0][1] = -1;
	pipes[1][0] = -1;
	pipes[1][1] = -1;
}

void	swap_pipes(int pipes[2][2])
{
	pipes[0][0] = pipes[1][0];
	pipes[0][1] = pipes[1][1];
	pipes[1][0] = -1;
	pipes[1][1] = -1;
}

void	close_first_pipe(t_cmd *cmdlst, int pipes[2][2])
{
	if (cmdlst->fd_in != STDIN_FILENO)
		close(cmdlst->fd_in);
	if (cmdlst->fd_out != STDOUT_FILENO)
		close(cmdlst->fd_out);
	close(pipes[0][0]);
	close(pipes[0][1]);
}

void	close_pipes(t_cmd *cmdlst, int pipes[2][2])
{
	if (cmdlst->fd_in != STDIN_FILENO)
		close(cmdlst->fd_in);
	if (cmdlst->fd_out != STDOUT_FILENO)
		close(cmdlst->fd_out);
	if (pipes[0][0] != 1)
		close(pipes[0][0]);
	close(pipes[1][1]);
	pipes[0][0] = -1;
	pipes[1][1] = -1;
}
