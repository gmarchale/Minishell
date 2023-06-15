/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/15 15:07:28 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;

	(void)argc; (void)argv;
	env = env_init(envp);
	if (!env)
	{
		printf("env failed\n");
		return(1);
	}
	while (1)
	{
		line = readline("\e[1;5;31m< Hell prompt >\e[0m ");
		//ft_printf(1, "%s\n", line);
		add_history(line);
		builtins_tester(&env, line);
		free(line);
	}
	free_list(env);
	return (0);
}
