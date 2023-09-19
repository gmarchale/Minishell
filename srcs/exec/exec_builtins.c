/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:26:33 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 14:30:47 by noloupe          ###   ########.fr       */
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
