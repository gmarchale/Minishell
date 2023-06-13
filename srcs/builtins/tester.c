/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:54 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/13 16:47:39 by noloupe          ###   ########.fr       */
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
	//print_env(*env);
	builtin_unset(env, "_");
	builtin_unset(env, "test");
	builtin_unset(env, "SECURITYSESSIONID");
	builtin_env(env);
	free_list(*env);
}