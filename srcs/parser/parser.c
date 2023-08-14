/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:16:25 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/07 14:43:03 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_lexlst	*parser(char *cmd_line, int *pipes)
{
	t_lexlst	*lexer_lst;

	lexer_lst = NULL;
	if (checker_quotes(cmd_line, 0, 0))
	{
		ft_printf(1, "Error : open quote\n");
		return (lexer_lst);
	}
	if (check_token(cmd_line))
		return (lexer_lst);
	lexer_lst = lexer(cmd_line);
	if (!lexer_lst)
		exit(EXIT_FAILURE);
	*pipes = count_pipes(lexer_lst); //creer une variable pipes dans main
	//parse_list(); //creer fonction qui prend la lex list et la met dans une liste chainee t_cmd
	return (lexer_lst);
}
