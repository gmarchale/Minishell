/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:55:22 by noloupe           #+#    #+#             */
/*   Updated: 2023/08/29 15:02:19 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*cmd_new_node(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		exit(shell->exit_value);
	new->cmd = NULL;
	new->fd_in = 0;
	new->fd_out = 1;
	new->next = NULL;
	return (new);
}

int	get_arr_size(t_lexlst *lexlst)
{
	int	count;

	count = 0;
	while (lexlst)
	{
		if (lexlst->type == e_word)
			count++;
		else if (lexlst->type == e_pipe)
			return (count);
		lexlst = lexlst->next;
	}
	return (count);
}

t_cmd	*lst_to_cmd(t_lexlst *lexlst)
{
	t_cmd		*cmd;
	t_cmd		*save;
	char		**arr;
	int			size;
	int			i;
	
	cmd = cmd_new_node();
	save = cmd;
	while (lexlst)
	{
		size = get_arr_size(lexlst);
		ft_printf(1, "size : %d + 1\n", size);
		arr = malloc(sizeof(char *) * size + 1);
		if (!arr)
			exit(shell->exit_value);
		i = 0;
		while (lexlst)
		{
			if (lexlst->type == e_word)
			{
				arr[i] = ft_strdup(lexlst->word);
				ft_printf(1, "arr[%d] = [%s]\n", i, arr[i]);
				i++;
			}
			else if (lexlst->type == e_pipe)
			{
				arr[i] = NULL;
				cmd->cmd = arr;
				cmd->next = cmd_new_node();
				cmd = cmd->next;
				break ;
			}
			lexlst = lexlst->next;	
		}
		if (lexlst)
			lexlst = lexlst->next;
	}
	arr[i] = NULL;
	return (save);
}
