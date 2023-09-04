/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:38:43 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/04 15:40:04 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler_ctrl_c(int sig)
{
	(void)sig;
	
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler(int input)
{
	signal(SIGQUIT, SIG_IGN);
	if (input == 0)
	{
		signal(SIGINT, signal_handler_ctrl_c);
	}
}
