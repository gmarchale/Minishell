/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:11:32 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/08 20:18:02 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char	*cmd)
{
	if (!cmd)
		exit (EXIT_FAILURE);
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
		//ft_printf(1, "waiting for pid %d\n", pids->pid);
		waitpid(pids->pid, NULL, 0);
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
	if (envp[i])
	{
		path_tab = ft_split(envp[i], ':');
		if (!path_tab)
		{			
			ft_printf(STDERR_FILENO, "minishell: error in path split\n");
			exit(EXIT_FAILURE);
		}
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
	}
	return (NULL);
}

void	exec_command(t_cmd *cmdlst, char **env)
{
	char	*path;
	
	path = get_path(cmdlst->cmd[0], env);
	if (!path)
	{
		if (!access(cmdlst->cmd[0], F_OK))
		{
			if (execve(cmdlst->cmd[0], cmdlst->cmd, env))
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			ft_printf(STDERR_FILENO, "minishell: %s: command not found\n", cmdlst->cmd[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (execve(path, cmdlst->cmd, env))
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	make_child(t_cmd *cmdlst, char **env, t_pids **pids)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		// if redir -- else
		dup2(STDIN_FILENO, fd[0]);
		dup2(STDOUT_FILENO, fd[1]);
		dup2(cmdlst->fd_in, STDIN_FILENO);
		dup2(cmdlst->fd_out, STDOUT_FILENO);
		exec_command(cmdlst, env);
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		add_pid_to_list(pids, pid);
		close(fd[0]);
		close(fd[1]);
	}
}

void	execute(t_cmd *cmdlst, char **env)
{
	t_pids	*pids;

	pids = NULL;
	while (cmdlst)
	{
		// save_base_fds();
		make_child(cmdlst, env, &pids);
		cmdlst = cmdlst->next;
		// restore_base_fds();
	}
	//sleep(1);
	wait_pids(pids);
	free_pids_list(pids);
}

void	print_env_arr(char **arr) //tmp
{
	while (*arr)
		ft_printf(1, "%s\n", *arr++);
}

void	execution(t_cmd *cmdlst)
{
	char	**env;

	if (!cmdlst)
		return ;
	if (is_solo_builtin(cmdlst))
		exec_builtin(cmdlst); //need to fix some builtins
	else
	{
		env = env_to_list();
		//print_env_arr(env);
		execute(cmdlst, env);
	}
}
