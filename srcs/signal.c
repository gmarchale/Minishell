/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:38:43 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/05 15:22:34 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	sig_input(int sig)
{
	(void)sig;
	
	// change exit value?
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
		signal(SIGINT, &sig_input);
	}
}
