/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:54 by noloupe           #+#    #+#             */
/*   Updated: 2023/06/12 15:02:16 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtins_tester(t_env **env)
{
	//builtin_pwd(env);
	//builtin_export(env, "test", "test");
	//builtin_unset(env, "SECURITYSESSIONID");
	print_env(*env);
}