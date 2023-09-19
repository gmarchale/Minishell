/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:11:32 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 15:13:16 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_command(t_cmd *cmdlst, char **env)
{
	char	*path;

	if (cmdlst->cmd[0][0] == '\0')
	{
		ft_printf(2, "minishell: %s: command not found\n", cmdlst->cmd[0]);
		exit(127);
	}
	if (is_builtin(cmdlst->cmd[0]))
		exec_child_builtin(cmdlst);
	path = get_path(cmdlst->cmd[0], env);
	if (!path)
	{
		if (!access(cmdlst->cmd[0], F_OK))
		{
			if (execve(cmdlst->cmd[0], cmdlst->cmd, env))
				perror_exit("execve", 126);
		}
		else
		{
			ft_printf(2, "minishell: %s: command not found\n", cmdlst->cmd[0]);
			exit(127);
		}
	}
	else if (execve(path, cmdlst->cmd, env))
		perror_exit("execve", 126);
}

void	make_child(t_cmd *cmdlst, char **env, t_pids **pids, int pipes[2][2])
{
	int	pid;

	if (pipe(pipes[1]) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		link_pipe(cmdlst, pipes);
		exec_command(cmdlst, env);
	}
	else
	{
		close_pipes(cmdlst, pipes);
		add_pid_to_list(pids, pid);
	}
}

void	last_child(t_cmd *cmdlst, char **env, t_pids **pids, int pipes[2])
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		last_link(cmdlst, pipes);
		exec_command(cmdlst, env);
	}
	else
	{
		if (pipes[0] != -1)
			close(pipes[0]);
		if (cmdlst->fd_out != STDOUT_FILENO)
			close(cmdlst->fd_out);
		if (cmdlst->fd_in != STDIN_FILENO)
			close(cmdlst->fd_in);
		add_pid_to_list(pids, pid);
		free_tab(env);
	}
}

void	execute(t_cmd *cmdlst, char **env)
{
	t_pids	*pids;
	int		pipes[2][2];

	pids = NULL;
	init_pipes(pipes);
	while (cmdlst->next)
	{
		if (cmdlst->fd_in == -2 || cmdlst->fd_out == -2 || !cmdlst->cmd[0])
		{
			close_first_pipe(cmdlst, pipes);
			cmdlst = cmdlst->next;
			continue ;
		}
		make_child(cmdlst, env, &pids, pipes);
		cmdlst = cmdlst->next;
		swap_pipes(pipes);
	}
	if ((cmdlst->fd_in != -2 || cmdlst->fd_out != -2) && cmdlst->cmd[0])
		last_child(cmdlst, env, &pids, pipes[0]);
	else
		close_first_pipe(cmdlst, pipes);
	wait_pids(pids);
	unlink("/tmp/heredoc.tmp");
	free_pids_list(pids);
}

void	execution(t_cmd *cmdlst)
{
	char	**env;
	int		base_in;
	int		base_out;

	signal_handler(1);
	if (!cmdlst)
		return ;
	if (is_solo_builtin(cmdlst))
	{
		shell->exit_value = 0;
		base_in = dup(STDIN_FILENO);
		base_out = dup(STDOUT_FILENO);
		change_fds(cmdlst);
		exec_builtin(cmdlst);
		restore_fds(base_in, base_out);
	}
	else
	{
		env = env_to_list();
		execute(cmdlst, env);
	}
	signal_handler(0);
}
