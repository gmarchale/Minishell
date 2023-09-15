/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:06 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/14 18:59:22 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf(1, "[%d]: %s\n", i, arr[i]);
		i++;
	}
}

void print_cmds(t_cmd *cmdlst)
{
	int	i;

	i = 1;
	while (cmdlst)
	{
		ft_printf(1, "\n");
		ft_printf(1, "--- node #%d ---\n", i);
		print_arr(cmdlst->cmd);
		ft_printf(1, "fd in : %d\n", cmdlst->fd_in);
		ft_printf(1, "fd out : %d\n", cmdlst->fd_out);
		cmdlst = cmdlst->next;
		i++;
	}
}

void	free_cmdlst(t_cmd *cmdlst)
{
	t_cmd	*previous;

	while (cmdlst)
	{
		free_tab(cmdlst->cmd);
		previous = cmdlst;
		cmdlst = cmdlst->next;
		free(previous);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_lexlst	*str_input;
	t_cmd		*cmdlst;
	t_env		*env;
	char		*line;


	(void)argv;
	if (argc != 1)
	{
		ft_printf(1, "Do not provide arguments\n");
		return (1);
	}
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
	shell->exit_value = 0;
	while (1)
	{
		signal_handler(0);
		line = readline("\e[1;5;96m\U0001f90d Heaven \U0001f90d \u2022\e[0m ");
		if (line == NULL)
			return (shell->exit_value); // free plus tard
		// if (!ft_strncmp(line, "echo $?", 8))
		// {
		// 	add_history(line);
		// 	ft_printf(1, "%d\n", shell->exit_value);
		// 	free(line);
		// 	continue ;
		// }
		if (line[0] != '\0')
		{
			add_history(line);
			str_input = lexer(line);
		}
		else
		{
			free(line);
			shell->exit_value = 0;
			continue ;
		}
		free(line);
		// if (!str_input)
		// 	return(shell->exit_value);
		// lexlst_to_cmd(str_input);
		/////
		// t_lexlst *tmp = NULL;
		
		// tmp = str_input;
		// while(tmp != NULL)
		// {
		// 	printf("old: %d	- {%s}\n", tmp->type, tmp->word);
		// 	tmp = tmp->next;
		// }
		// printf("\n");
		/////
		if (parser(str_input))
		{
			lexlst_clear(&str_input);
			shell->exit_value = 2;
			continue ;
		}
		expander(str_input);
		/////
		// tmp = NULL;
		// tmp = str_input;
		// while(tmp != NULL)
		// {
		// 	printf("new: %d	- {%s}\n", tmp->type, tmp->word);
		// 	tmp = tmp->next;
		// }
		// printf("\n");
		/////
		cmdlst = lst_to_cmd(str_input);
		free_lexlst(str_input);
		// print_cmds(cmdlst);
		execution(cmdlst);
		free_cmdlst(cmdlst);
	}
	free_env_list(env);
	free(shell);
	return (0);
}
