/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:11:32 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/08 18:18:34 by noloupe          ###   ########.fr       */
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

int	is_solo_builtin(t_cmd *cmd_l)
{
	if (!cmd_l->next && is_builtin(cmd_l->cmd[0]))
		return (1);
	return (0);
}

void	exec_builtin(t_cmd *cmd_l)
{	
	if (!cmd_l || !cmd_l->cmd[0])
		return ;
	if (key_check(cmd_l->cmd[0], "echo"))
		builtin_echo(cmd_l->cmd);
	else if (key_check(cmd_l->cmd[0], "cd"))
		builtin_cd(cmd_l->cmd);
	else if (key_check(cmd_l->cmd[0], "pwd"))
		builtin_pwd();
	else if (key_check(cmd_l->cmd[0], "export"))
		builtin_export(cmd_l->cmd);
	else if (key_check(cmd_l->cmd[0], "unset"))
		builtin_unset(cmd_l->cmd);
	else if (key_check(cmd_l->cmd[0], "env"))
		builtin_env(cmd_l->cmd, ENV);
	else if (key_check(cmd_l->cmd[0], "exit"))
		builtin_exit(cmd_l->cmd);
	else
		ft_printf(1, "minishell: %s: command not found\n", cmd_l->cmd[0]);
}

void	execution(t_cmd *cmd_l)
{
	if (!cmd_l)
		return ;
	if (is_solo_builtin(cmd_l))
	{
		exec_builtin(cmd_l);
		//ft_printf(2, "works\n");
	}
	else
	{
		ft_printf(2, "does not work\n");
	}
}
