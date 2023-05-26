/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:54 by noloupe           #+#    #+#             */
/*   Updated: 2023/05/26 14:23:05 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void builtins_tester(t_env *env)
{
	builtin_pwd(env);
	builtin_export(env, "1test", NULL);
	print_env(env);
}