/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/05/25 13:29:44 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env *env;

	(void)argc; (void)argv;
	env = env_init(envp);
	if (!env)
	{
		printf("env failed\n");
		return(1);
	}
	print_env(env);
	return (0);
}
