/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:50:04 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 14:50:25 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_fds(t_cmd *cmdlst)
{
	if (cmdlst->fd_in != -2 && cmdlst->fd_in != STDIN_FILENO)
	{
		if (dup2(cmdlst->fd_in, STDIN_FILENO) == -1)
			perror_exit("dup2", EXIT_FAILURE);
		close(cmdlst->fd_in);
	}
	if (cmdlst->fd_out != -2 && cmdlst->fd_out != STDOUT_FILENO)
	{
		if (dup2(cmdlst->fd_out, STDOUT_FILENO) == -1)
			perror_exit("dup2", EXIT_FAILURE);
		close(cmdlst->fd_out);
	}
}

void	restore_fds(int base_in, int base_out)
{
	if (dup2(base_in, STDIN_FILENO) == -1)
		perror_exit("dup2", EXIT_FAILURE);
	if (dup2(base_out, STDOUT_FILENO) == -1)
		perror_exit("dup2", EXIT_FAILURE);
	close(base_in);
	close(base_out);
}
