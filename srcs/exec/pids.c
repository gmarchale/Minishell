/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:31:29 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/19 14:31:42 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_pids	*add_new_pid(int pid)
{
	t_pids	*new;

	new = malloc(sizeof(t_pids));
	if (!new)
		exit(shell->exit_value);
	new->pid = pid;
	new->next = NULL;
	return (new);
}

void	add_pid_to_list(t_pids **pids, int pid)
{
	t_pids	*save;

	if (!*pids)
		*pids = add_new_pid(pid);
	else
	{
		save = *pids;
		while ((*pids)->next)
			*pids = (*pids)->next;
		(*pids)->next = add_new_pid(pid);
		*pids = save;
	}
}

void	wait_pids(t_pids *pids)
{
	int	status;
	int	sig;

	while (pids)
	{
		status = 0;
		waitpid(pids->pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_value = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			sig = WTERMSIG(status);
			if (sig == SIGINT)
				shell->exit_value = 130;
			else if (sig == SIGQUIT)
				shell->exit_value = 131;
		}
		pids = pids->next;
	}
}

void	free_pids_list(t_pids *pids)
{
	t_pids	*previous;

	while (pids)
	{
		previous = pids;
		pids = pids->next;
		free(previous);
	}
}
