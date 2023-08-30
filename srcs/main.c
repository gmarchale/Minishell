/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/08/29 21:18:54 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#include <fcntl.h>

/*
int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;
	t_lexlst	*str_input;

	(void)argc;
	(void)argv;
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
*/

int	create_heredoc(char *lim) //(t_lexlst lim)
{
	int	fd;
	size_t size;
	char *line;

	fd = open("heredoc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644); //change path
	if (!fd)
		return (1);
	while (1)
	{
		line = readline("heredoc> ");
		size = ft_strlen(lim);
		if (ft_strlen(line) > size)
			size = ft_strlen(line);
		if (ft_strncmp(line, lim, size)) //!= lim->word)
			ft_printf(fd, "%s\n", line);
		else
		{
			ft_printf(fd, "Found delimiter\n"); // a delete
			return (fd);
		}
	}
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;
	t_lexlst	*str_input;

	(void)argc;
	(void)argv;
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
		else
			create_heredoc("lim");
		free(line);
	}
	free_list(env);
	return (0);
}
