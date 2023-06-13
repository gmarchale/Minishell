/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:54 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/13 16:28:00 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtins_tester(t_env **env)
{
	//builtin_pwd(env);
	builtin_export(env, "test", "test");
	builtin_export(env, "SHLVL", "test2");
	builtin_export(env, "%test", "test3");
	builtin_export(env, "test", "test4");
	//builtin_unset(env, "SECURITYSESSIONID");
	//print_env(*env);
	builtin_env(env);
	free_list(*env);
}