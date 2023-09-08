/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:38:43 by gmarchal          #+#    #+#             */
/*   Updated: 2023/09/08 17:46:13 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//SIGINT = Ctrl+C
//SIG_QUIT = Ctrl+backslash

static void	get_prompt(int sig)
{
	(void) sig;
	//changer exit_value = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	rl_new_line(int sig)
{
	(void) sig;
	write(1, "\n", 1);
	rl_on_new_line();
}

static void	sig_ctrl_c(int sig)
{
	(void) sig;
	exit(130);
	rl_redisplay();
}
static void	sig_backslash(int sig)
{
	(void) sig;
	rl_redisplay();
}

void	signal_handler(int input) // Appeler la fonction au debut de minishell et dans la boucle while avant le readline
{
	signal(SIGQUIT, SIG_IGN);
	if (input == 0)
		signal(SIGINT, &get_prompt);
	else if (input == 1) // cat / grep 
	{
		signal(SIGINT, &rl_new_line);
		signal(SIGQUIT, &rl_new_line);
	}
	else if (input == 2) // a tester quand il y aura le heredoc
	{
		//signal(SIGINT, &sig_ctrl_c);
		signal(SIGINT, &rl_new_line);
		signal(SIGQUIT, &sig_backslash);
	}
	else if (input == 3)
		signal(SIGINT, &sig_ctrl_c);
	else
		signal(SIGINT, &get_prompt);
}
