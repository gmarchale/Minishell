/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <gmarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/05 15:22:48 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;
	t_lexlst	*str_input;

	(void)argc;
	(void)argv;
	signal_handler(0);
	str_input = NULL;
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
		if (line == NULL)
			return (0); // free plus tard
		if (line[0] != '\0')
			add_history(line);
		builtins_tester(line);
		str_input = lexer(line);//test
		while(str_input != NULL)
		{
			printf("%s\n", str_input->word);
			str_input = str_input->next;
		}
		free(line);
	}
	free_list(env);
	return (0);
}
