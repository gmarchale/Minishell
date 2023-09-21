/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/21 14:38:17 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	read_and_tokenize(t_lexlst **str_input)
{
	char	*line;

	signal_handler(0);
	line = readline("\e[1;5;96m\U0001f90d Heaven \U0001f90d \u2022\e[0m ");
	if (line == NULL)
		exit(g_shell->exit_value);
	if (line[0] != '\0')
	{
		add_history(line);
		*str_input = lexer(line);
	}
	if (!*str_input)
	{
		free(line);
		g_shell->exit_value = 0;
		return (1);
	}
	free(line);
	return (0);
}

void	loop_shell(void)
{
	t_lexlst	*str_input;
	t_cmd		*cmdlst;

	str_input = NULL;
	while (1)
	{
		if (read_and_tokenize(&str_input))
			continue ;
		if (parser(str_input))
		{
			lexlst_clear(&str_input);
			g_shell->exit_value = 2;
			continue ;
		}
		expander(str_input);
		cmdlst = lst_to_cmd(str_input);
		lexlst_clear(&str_input);
		execution(cmdlst);
		free_cmdlst(cmdlst);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env		*env;

	if (argc != 1 || argv[1])
		return (ft_printf(2, "Do not provide arguments\n"));
	g_shell = malloc(sizeof(t_shell));
	if (!g_shell)
		return (1);
	if (*envp)
		env = env_init(envp);
	else
		env = create_env();
	if (!env)
	{
		free(g_shell);
		ft_printf(2, "env failed\n");
		exit(1);
	}
	g_shell->env = env;
	g_shell->exit_value = 0;
	loop_shell();
	free_env_list(env);
	free(g_shell);
	return (0);
}
