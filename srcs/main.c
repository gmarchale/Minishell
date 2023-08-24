/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/24 18:20:00 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;
	t_lexlst	*str_input;


	(void)argv;
	if (argc != 1)
	{
		ft_printf(1, "Do not provide arguments\n");
		return (1);
	}
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
		//builtins_tester(line);
		str_input = lexer(line);
		// if (!str_input)
		// 	return(shell->exit_value);
		free(line);
		// lexlst_to_cmd(str_input);
		/////
		t_lexlst *tmp = NULL;
		
		tmp = str_input;
		while(str_input != NULL)
		{
			printf("type: %d	- {%s}\n", str_input->type, str_input->word);
			str_input = str_input->next;
		}
		str_input = tmp;
		/////
		parser(str_input);
		expander(str_input);
		free_lexlst(str_input);
	}
	free_list(env);
	free(shell);
	return (0);
}
