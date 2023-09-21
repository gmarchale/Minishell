/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noloupe <noloupe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:21:03 by noloupe           #+#    #+#             */
/*   Updated: 2023/09/21 14:21:37 by noloupe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_prompt(int sig)
{
	(void) sig;
	g_shell->exit_value = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	rl_new_line(int sig)
{
	(void) sig;
	write(1, "\n", 1);
	rl_on_new_line();
}

void	backslash_new_line(int sig)
{
	(void) sig;
	write(1, "Quit: 3\n", 8);
	rl_on_new_line();
}

void	sig_ctrl_c(int sig)
{
	(void) sig;
	rl_redisplay();
	exit(130);
}

void	sig_backslash(int sig)
{
	(void) sig;
	rl_redisplay();
}
