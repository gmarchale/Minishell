/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:54 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/15 10:35:32 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtins_tester(t_env **env)
{
	char **str;
	char **str2;
	
	//builtin_pwd(env);
	//print_env(*env);
	builtin_export(env, "test", "test");
	builtin_export(env, "SHLVL", "test2");
	builtin_export(env, "%test", "test3");
	builtin_export(env, "test", "test4");
	builtin_unset(env, "_");
	builtin_unset(env, "test");
	builtin_unset(env, "SECURITYSESSIONID");
	builtin_env(env);
	free_list(*env);
	str = ft_split("oui oui baguette", ' ');
	str2 = ft_split("-n -nnnnnn -n -n -nnnnann -n test test test", ' ');
	builtin_echo(str);
	builtin_echo(str2);
	builtin_exit(0);
}