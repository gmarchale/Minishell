/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:07:25 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/19 14:57:38 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	error_msg(char c)
{
	printf("Minishell: Syntax Error near unexpected token `%c'\n", c);
	return (1);
}

int	ft_exit_failure(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
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
