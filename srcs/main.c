/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/14 13:40:21 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;

	(void)argc;
	(void)argv;
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (1);
	if (*envp)
		env = env_init(envp);
	else
		env = create_env();
	if (!env)
	{
		printf("env failed\n");
		free(shell);
		exit(1);
	}
	shell->env = env;
	while (1)
	{
		line = readline("\e[1;5;96m\U0001f90d Heaven \U0001f90d \u2022\e[0m ");
		add_history(line);
		builtins_tester(line);
		//lexer(line);
		//execution(NULL);
		free(line);
	}
	free_list(env);
	return (0);
}
