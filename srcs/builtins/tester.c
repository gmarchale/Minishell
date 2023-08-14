/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:54 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/14 13:48:42 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtins_tester(char *line)
{
	char	**s_line;

	if (!line)
		exit(EXIT_FAILURE);
	s_line = ft_split(line, ' ');
	if (!s_line || !s_line[0])
		return ;
	if (key_check(s_line[0], "echo"))
		builtin_echo(s_line);
	else if (key_check(s_line[0], "cd"))
		builtin_cd(s_line);
	else if (key_check(s_line[0], "pwd"))
		builtin_pwd();
	else if (key_check(s_line[0], "export"))
		builtin_export(s_line);
	else if (key_check(s_line[0], "unset"))
		builtin_unset(s_line);
	else if (key_check(s_line[0], "env"))
		builtin_env(s_line, ENV);
	else if (key_check(s_line[0], "exit"))
		builtin_exit(s_line);
	else
		ft_printf(1, "minishell: %s: command not found\n", s_line[0]);
}
