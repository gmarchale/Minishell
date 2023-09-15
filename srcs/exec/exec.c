/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:11:32 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/15 12:52:31 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char	*cmd)
{
	if (!cmd)
		return (0);
	if ((key_check(cmd, "echo")) || (key_check(cmd, "cd")) || \
		(key_check(cmd, "pwd")) || (key_check(cmd, "export")) || \
		(key_check(cmd, "unset")) || (key_check(cmd, "env")) || \
		(key_check(cmd, "exit")))
		return (1);
	else
		return (0);
}

int	is_solo_builtin(t_cmd *cmdlst)
{
	if (!cmdlst->next && is_builtin(cmdlst->cmd[0]))
		return (1);
	return (0);
}

void	exec_builtin(t_cmd *cmdlst)
{
	if (key_check(cmdlst->cmd[0], "echo"))
		builtin_echo(cmdlst->cmd);
	else if (key_check(cmdlst->cmd[0], "cd"))
		builtin_cd(cmdlst->cmd);
	else if (key_check(cmdlst->cmd[0], "pwd"))
		builtin_pwd();
	else if (key_check(cmdlst->cmd[0], "export"))
		builtin_export(cmdlst->cmd);
	else if (key_check(cmdlst->cmd[0], "unset"))
		builtin_unset(cmdlst->cmd);
	else if (key_check(cmdlst->cmd[0], "env"))
		builtin_env(cmdlst->cmd, ENV);
	else if (key_check(cmdlst->cmd[0], "exit"))
		builtin_exit(cmdlst->cmd);
}

void	exec_child_builtin(t_cmd *cmdlst)
{
	if (key_check(cmdlst->cmd[0], "echo"))
		builtin_echo(cmdlst->cmd);
	else if (key_check(cmdlst->cmd[0], "cd"))
		builtin_cd(cmdlst->cmd);
	else if (key_check(cmdlst->cmd[0], "pwd"))
		builtin_pwd();
	else if (key_check(cmdlst->cmd[0], "export"))
		builtin_export(cmdlst->cmd);
	else if (key_check(cmdlst->cmd[0], "unset"))
		builtin_unset(cmdlst->cmd);
	else if (key_check(cmdlst->cmd[0], "env"))
		builtin_env(cmdlst->cmd, ENV);
	else if (key_check(cmdlst->cmd[0], "exit"))
		builtin_exit(cmdlst->cmd);
	exit(EXIT_SUCCESS);
}

int	get_env_size(void)
{
	t_env	*save;
	int		i;

	save = shell->env;
	i = 0;
	while (save)
	{
		i++;
		save = save->next;
	}
	return (i);
}

char	**env_to_list(void)
{
	t_env	*save;
	char	**env;
	int		i;

	env = malloc(sizeof(char *) * (get_env_size() + 1));
	if (!env)
		exit(shell->exit_value);
	save = shell->env;
	i = 0;
	while (save)
	{
		env[i] = ft_strdup(save->key);
		env[i] = strjoin_free_first(env[i], "=");
		env[i] = strjoin_free_first(env[i], save->value);
		i++;
		save = save->next;
	}
	env[i] = NULL;
	return (env);
}

t_pids	*add_new_pid(int pid)
{
	t_pids	*new;

	new = malloc(sizeof(t_pids));
	if (!new)
		exit(shell->exit_value);
	new->pid = pid;
	new->next = NULL;
	return (new);
}

void	add_pid_to_list(t_pids **pids, int pid)
{
	t_pids	*save;

	if (!*pids)
		*pids = add_new_pid(pid);
	else
	{
		save = *pids;
		while ((*pids)->next)
			*pids = (*pids)->next;
		(*pids)->next = add_new_pid(pid);
		*pids = save;
	}
}

void	wait_pids(t_pids *pids)
{
	while (pids)
	{
		waitpid(pids->pid, &shell->exit_value, 0);
		if (shell->exit_value >= 256)
			shell->exit_value = shell->exit_value / 256;
		pids = pids->next;
	}
}

void	free_pids_list(t_pids *pids)
{
	t_pids	*previous;

	while (pids)
	{
		previous = pids;
		pids = pids->next;
		free(previous);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**path_tab;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path_tab = ft_split(envp[i], ':');
	if (!path_tab)
		return (NULL);
	i = -1;
	while (path_tab[++i])
	{
		path = ft_strjoin(path_tab[i], "/");
		path = strjoin_free_first(path, cmd);
		if (!access(path, F_OK))
		{
			free_tab(path_tab);
			return (path);
		}
		free(path);
	}
	free_tab(path_tab);
	return (NULL);
}

void	perror_exit(char *str, int value)
{
	perror(str);
	exit(value);
}

void	exec_command(t_cmd *cmdlst, char **env)
{
	char	*path;
	
	if (cmdlst->cmd[0][0] == '\0')
	{
		ft_printf(STDERR_FILENO, "minishell: %s: command not found\n", cmdlst->cmd[0]);
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
			ft_printf(STDERR_FILENO, "minishell: %s: command not found\n", cmdlst->cmd[0]);
			exit(127);
		}
	}
	else if (execve(path, cmdlst->cmd, env))
		perror_exit("execve", 126);
}

void	link_pipe(t_cmd *cmdlst, int pipes[2][2])
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
	}
}

void	execute(t_cmd *cmdlst, char **env)
{
	t_pids	*pids;
	int		pipes[2][2];

	pids = NULL;
	pipes[0][0] = -1;
	pipes[0][1] = -1;
	pipes[1][0] = -1;
	pipes[1][1] = -1;
	while (cmdlst->next)
	{
		if (cmdlst->fd_in == -2 || cmdlst->fd_out == -2 || !cmdlst->cmd[0])
		{
			if (cmdlst->fd_in != STDIN_FILENO)
				close(cmdlst->fd_in);
			if (cmdlst->fd_out != STDOUT_FILENO)
				close(cmdlst->fd_out);
			close(pipes[0][0]);
			close(pipes[0][1]);
			cmdlst = cmdlst->next;
			continue ;
		}
		make_child(cmdlst, env, &pids, pipes);
		cmdlst = cmdlst->next;
		pipes[0][0] = pipes[1][0];
		pipes[0][1] = pipes[1][1];
		pipes[1][0] = -1;
		pipes[1][1] = -1;
	}
	if ((cmdlst->fd_in != -2 || cmdlst->fd_out != -2) && cmdlst->cmd[0])
		last_child(cmdlst, env, &pids, pipes[0]);
	else
	{
		if (cmdlst->fd_in != STDIN_FILENO)
			close(cmdlst->fd_in);
		if (cmdlst->fd_out != STDOUT_FILENO)
			close(cmdlst->fd_out);
		close(pipes[0][0]);
		close(pipes[0][1]);
	}
	wait_pids(pids);
	unlink("/tmp/heredoc.tmp");
	free_pids_list(pids);
}

void	execution(t_cmd *cmdlst)
{
	char	**env;

	signal_handler(1);
	if (!cmdlst)
		return ;
	if (is_solo_builtin(cmdlst))
		exec_builtin(cmdlst); //need to fix some builtins
	else
	{
		env = env_to_list();
		execute(cmdlst, env);
	}
	signal_handler(0);
}
