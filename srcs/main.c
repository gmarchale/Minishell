/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/06/28 21:50:17 by gmarchal         ###   ########.fr       */
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
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (1);
	env = env_init(envp);
	if (!env)
	{
		printf("env failed\n");
		return(1);
	}
	shell->env = env;
	while (1)
	{
		line = readline("\e[1;5;96m\U0001f90d Heaven \U0001f90d \u2022\e[0m ");
		if (line == NULL)
			return (0); // free plus tard
		//ft_printf(1, "%s\n", line);
		if (line[0] != '\0')
			add_history(line);
		builtins_tester(line);
		//str_input = tokenize(line);//test
		str_input = lexer(line);//test
		while(str_input != NULL)
		{
			printf("%s\n", str_input->word);
			str_input = str_input->next;
		}
		//printf("%s\n", str_input->content);
		//printf_list(str_input);
		free(line);
	}
	free_list(env);
	return (0);
}
