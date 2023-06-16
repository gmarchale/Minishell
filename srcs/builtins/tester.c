/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:54 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/16 16:14:33 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtins_tester(char *line)
{
	char **s_line;
	
	if (!line)
		exit(EXIT_FAILURE);
	s_line = ft_split(line, ' ');
	if (!s_line)
		return ;
	// ft_printf(1, "found %s\n", s_line[0]);
	if (key_check(s_line[0], "echo"))
		builtin_echo(s_line);
	// else if (key_check(s_line[0], "cd"))
	// 	builtin_cd(s_line);
	// else if (key_check(s_line[0], "pwd"))
	// 	builtin_pwd(s_line);
	// else if (key_check(s_line[0], "export"))
	// 	builtin_export(s_line);
	// else if (key_check(s_line[0], "unset"))
	// 	builtin_unset(s_line);
	else if (key_check(s_line[0], "exit"))
		builtin_exit(s_line);
}